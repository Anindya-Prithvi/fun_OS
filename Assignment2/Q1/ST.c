#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/time.h>
#include<string.h>

/*Functionality of ST: 
We require a similar SIGALRM handler for ST. The ST process should read
the CPU timestamp counter (using inline assembly to run RDTSC instruction),
and coverts into a human readable string (i.e. representing the current date and time),
at every interval. The interval can be set using the setitimer() system call, 
that raises then SIGALRM signal everytime the timeout elapses, that is trapped 
by an appropriate signal handler. The random number should be obtained 
(using the inline RDTSC instruction), in the SIGALRM handler function. Much 
like SR, the ST’s SIGALRM handler should enqueue the string along with the 
SIGTERM signal  and thereafter send it to S1 (using kill()). ST’s SIGTERM 
signal handler should print the string supplied by ST*/
pid_t s1;
char* timestring;
float procspeed;

void alarmed(int signal){
    u_int32_t rd_hi;
    u_int32_t rd_lo;
    asm volatile (
        "RDTSC\n\t"
        :"=d" (rd_hi), "=a" (rd_lo)
        :
    );
    u_int64_t rd_64 = (u_int64_t) rd_hi<<32;
    rd_64 = rd_64 + rd_lo;
    rd_64/= (long) procspeed * 1000000; //assuming baseclock @2419.200Mhz
    ///proc/cpuinfo --> new intel has constant_tsc => the rdtsc will only count cycles since start
    
	int h = (rd_64/3600)%100; //otherwise more than 8 bytes
	int m = (rd_64 -(3600*h))/60;
	int s = (rd_64 -(3600*h)-(m*60));
    timestring = malloc(9); //null ptr
    snprintf(timestring, 9, "%02d:%02d:%02d", h,m,s); //including null ptr 
    //8 byte array

    union sigval value;
    value.sival_ptr = (void*) *((long*) timestring);
    sigqueue(s1, SIGTERM, value);
}

void termed(int signal){
    printf("%s\n",timestring);
}

int main(int argc, char const *argv[]){
    if(argc==1) exit(0);
    FILE *cmd = popen("grep -m1 'cpu MHz.*' /proc/cpuinfo", "r");
    char* buff = malloc(sizeof(char)*100);
    fread(buff, 1, 100, cmd);
    sscanf(buff, "%*[^0123456789]%f%*[\n]", &procspeed);
    fclose(cmd);
    struct itimerval initial;
    initial.it_value.tv_sec = 1;
    initial.it_value.tv_usec =  0;
    initial.it_interval.tv_sec = 1;
    initial.it_interval.tv_usec = 0;
    int err = setitimer(ITIMER_REAL, &initial, NULL);
    if (err==-1){
        perror("Failed to get alarmed lol\n");
    }
    if(argc==2){
        s1 = atoi(*++argv);
        // printf("%d\n",s1);
    }
    if(signal(SIGALRM, alarmed)==SIG_ERR){
        perror("Failed to catch SIGALRM");
    }
    if(signal(SIGTERM, termed)==SIG_ERR){
        perror("Failed to catch SIGTERM");
    }
    while(1){
        pause();
    }
    return 0;
}