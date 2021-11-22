#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/time.h>
#include<regex.h>

#define PATH_BUF_SIZ 800

void sigtermhandler_S1(int signum, siginfo_t* info, void* extra){
    void* ptr_val = info->si_value.sival_ptr;
    long value = (long) ptr_val;
    char* tst = calloc(__SIZEOF_LONG__+1, sizeof(char));
    memcpy(tst, &value, __SIZEOF_LONG__);
    regex_t regex;
    int reti;
    reti = regcomp(&regex, "[0-9][0-9]:[0-9][0-9]:[0-9][0-9]",0);
    if(reti) perror("regex fail\n");
    if(!regexec(&regex, tst, 0, NULL, 0)){
        //minute chances of showing random number as time
        printf("time is: %s\n", tst);
    }
    else{
        printf("random value: %lu\n", value);
    }
}

int main(){
    printf("Hello! Program is starting\n");
    pid_t p1 = fork();
    if(p1==-1){
        perror("fork fail\n");
        exit(1);
    }
    else if(p1==0){
        // S1
        struct sigaction s1handler;
        s1handler.sa_flags = SA_SIGINFO; 
        s1handler.sa_sigaction = &sigtermhandler_S1;
        if (sigaction(SIGTERM, &s1handler, NULL) == -1) { 
            perror("SIGTERM REGISTRATION FAILED");
            exit(1);
        }
        while(1){
            pause();
        }
    }
    else{
        pid_t sr = fork();
        if(sr==-1){
            perror("forking for sr fail\n");
            exit(1);
        }
        else if(sr==0){
            char* buf = malloc(PATH_BUF_SIZ);
            getcwd(buf, PATH_BUF_SIZ);
            char* ptoexec = "/SR";
            strcat(buf, ptoexec);
            // printf("%s\n",buf);
            // printf("Child SR process\n");
            char* intbuf = malloc(sizeof(char)*10); //assuming max 10 digit int
            snprintf(intbuf, 10, "%d", p1);
            char* args[] = {buf, intbuf, NULL};
            int e = execv(buf, args);
            perror("Could not create SR\n");
            free(buf);
            exit(1);
        }
        pid_t st = fork();
        if(st==-1){
            perror("forking for st failed\n");
            exit(1);
        }
        else if (st==0){
            // printf("Child ST process\n");
            char* buf = malloc(PATH_BUF_SIZ);
            getcwd(buf, PATH_BUF_SIZ);
            char* ptoexec = "/ST";
            strcat(buf, ptoexec);
            // printf("%s\n",buf);
            // printf("Child SR process\n");
            char* intbuf = malloc(sizeof(char)*10);
            snprintf(intbuf, 10, "%d", p1);
            char* args[] = {buf, intbuf, NULL};
            int e = execv(buf, args);
            perror("Could not create ST\n");
            free(buf);
            exit(1);
        }
        // process no longer needed. Exit
        exit(0);
    }
    return 0;
}