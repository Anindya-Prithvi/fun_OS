#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

// The first exercise deals using process creation system call, fork(). You need to
// write a program that spawns a child process, using the fork() system call. The
// child process reads a CSV file, presented with the assignment, that has (fake)
// student IDs and grades of various assignments. This child process computes the
// average score of each assignment across students of section ‘A’, and thereafter
// prints the details of these assignments (of section ‘A’, ). The parent process
// does the same operation, on the same CSV file but for assignments given to
// students of section ‘B’.
// The parent process must wait for the child process to terminate, by using the
// system call waitpid(). The child process must call the exit() system callonce
// its execution ends.

void operate(char section, char buf[]){
    char greet[33] = "Showing statistics of section ";
    greet[30] = section;
    greet[31] = '\n';
    ssize_t written = write(STDOUT_FILENO, greet, 33);
    if(written==-1){
        fprintf(stderr, "Writing to STDOUT failed\n");
        exit(1);
    }
    char* end;
    char* token_newln = strtok_r(buf, "\n", &end);//POSIX tok_r
    if(token_newln==NULL) {
        fprintf(stderr, "Could not tokenize\n");
        exit(1);
    }
    int i=0;
    char* ch = token_newln;
    while(*ch!='\r'){
        if(*ch==',') ++i;
        ++ch;
    }
    --i;
    int arr[i];
    int j;
    for(j=0;j<i;j++) arr[j]=0;
    token_newln = strtok_r(NULL,"\n",&end);
    int sec_members=0;
    while(token_newln!=NULL){
        char* endcom; j=0;
        char* csep = strtok_r(token_newln, ",",&endcom);
        while(csep!=NULL){
            if((j==1)&&(*csep!=section)) break;
            if((j==1)&&(*csep==section)) ++sec_members;
            if(j>1){
                arr[j-2]+=atoi(csep);
            }++j;
            csep = strtok_r(NULL,",",&endcom);
        }
        token_newln = strtok_r(NULL,"\n",&end);
    }
    for(j=0;j<i;j++){
        int asnmavg = arr[j]/sec_members;
        char greet[19] = "Assignment  : ";
        greet[11] = j+'0'+1; //assuming only <10 assignments
        greet[17] = '\n';
        greet[14] = asnmavg/100+'0';//hundreds
        greet[15] = (asnmavg-asnmavg/100*100)/10+'0';//tens
        greet[16] = (asnmavg-asnmavg/100*100-asnmavg/10*10)+'0';//ones
        ssize_t written = write(STDOUT_FILENO, greet, 19);
        if(written==-1){
            fprintf(stderr, "Writing to STDOUT failed\n");
            exit(1);
        }
    }
    return;
}

int main(int argc, char const* argv[]){
    int fd = open("student_record.csv", O_RDONLY);
    if(fd==-1) {
        fprintf(stderr, "FILE could not be opened\n");
        exit(1);
    }
    char buf[BUFSIZ];
    ssize_t rd = read(fd, buf, BUFSIZ);
    if(rd==-1){
        fprintf(stderr, "Reading from file descriptor to buf failed\n");
        exit(1);
    }
    if(close(fd)==-1){
        fprintf(stderr, "Closing failed\n");
        exit(1);
    }
    pid_t rc = fork();
    if(rc<0){
        fprintf(stderr, "Forking failed\n");
        exit(1);
    }
    else if(rc==0){
        //hi child process
        operate('A', buf);
        exit(0);
    }
    else{
        //parent
        pid_t rc_wait = waitpid(rc,NULL,0); //rc_wait usable for debugging
        if(rc_wait==-1) fprintf(stderr, "Waiting failed\n");
        //waiting for children :)
        operate('B', buf);
    }

    return 0;
}
