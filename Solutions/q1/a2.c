#include<stdio.h>
#include<pthread.h>
#include<assert.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

typedef struct __myarg_t {
    char section;
    int* data;
    int row;
    int col;
} myarg_t;

void* mythread(void* arg){
    myarg_t* argument = (myarg_t*) arg;
    int section = (int) argument->section;
    int rows = argument->row;
    int col = argument->col;
    int* data = argument->data;
    int i,j;
    int memsec = 0;
    int* avgscr = calloc(6,sizeof(int));
    if(avgscr == NULL) {
        fprintf(stderr, "Calloc failed");
        exit(1);
    }
    for(i=0; i<rows; i++){
        for(j=0; j<col; j++){
            if(j==0){
                if(data[i*7+j]==section){
                    break;
                }
                else {
                    ++memsec;
                    continue;
                }
            }
            avgscr[j-1]+=data[i*7+j];
        }
    }

    for(j=0;j<6;j++) {
        avgscr[j]/=memsec;
        char greet[27] = "Section   Assignment  : ";
        greet[21] = j+'0'+1; //assuming only <10 assignments
        greet[26] = '\n';
        greet[8] = section;
        greet[23] = avgscr[j]/100+'0';//hundreds
        greet[24] = (avgscr[j]-avgscr[j]/100*100)/10+'0';//tens
        greet[25] = (avgscr[j]-avgscr[j]/100*100-avgscr[j]/10*10)+'0';//ones
        ssize_t written = write(STDOUT_FILENO, greet, 27);
        if(written==-1){
            fprintf(stderr, "Writing to STDOUT failed\n");
            exit(1);
        }
    }
    return avgscr;
}


int main(int argc, char const* argv[]) {
    pthread_t p1;
    pthread_t p2;
    int* m1;
    int* m2;
    

    int fd = open("student_record.csv", O_RDONLY);
    if(fd==-1) {
        fprintf(stderr, "FILE could not be opened\n");
        exit(1);
    }
    char* buf = calloc(BUFSIZ, sizeof(char));
    if(buf == NULL) {
        fprintf(stderr, "Calloc failed");
        exit(1);
    }
    ssize_t rd = read(fd, buf, BUFSIZ);
    if(rd==-1){
            fprintf(stderr, "reading failed\n");
            exit(1);
        }
    if(close(fd)==-1) {
        fprintf(stderr, "Closing failed\n");
        exit(1);
    };

    char* end = NULL;
    char* token_newln = strtok_r(buf, "\n", &end);//POSIX tok_r
    token_newln = strtok_r(NULL,"\n",&end);//first line useless
    int i = 7; //columns
    char* trv = end;
    int total_rows = 0;
    while(*++trv!='\0') if(*trv=='\n') ++total_rows;
    ++total_rows;

    int* data = malloc(total_rows*i*sizeof(int));
    if(data == NULL) {
        fprintf(stderr, "Malloc failed");
        exit(1);
    }

    int j;
    i = 0;
    while(token_newln!=NULL){
        char* endcom; j=0;
        char* csep = strtok_r(token_newln, ",",&endcom);
        while(csep!=NULL){
            if(j==1) data[i*7+0] = *csep;
            else if(j>0) data[i*7+j-1]=atoi(csep);
            ++j;
            csep = strtok_r(NULL,",",&endcom);
        }
        ++i;
        token_newln = strtok_r(NULL,"\n",&end);
    }

    myarg_t arg1 = {'A', data, total_rows, 7};
    myarg_t arg2 = {'B', data, total_rows, 7};


    int rc1 = pthread_create(&p1, NULL, mythread, &arg1);
    if(rc1!=0){
        fprintf(stderr, "Thread failed");
        exit(1);
    }
    int rc2 = pthread_create(&p2, NULL, mythread, &arg2);
    if(rc2!=0){
        fprintf(stderr, "Thread failed");
        exit(1);
    }
    rc2 = pthread_join(p2, (void**) &m2);
    if(rc2!=0){
        fprintf(stderr, "Thread failed");
        exit(1);
    }
    rc1 = pthread_join(p1, (void**) &m1);
    if(rc1!=0){
        fprintf(stderr, "Thread failed");
        exit(1);
    }
    
    int netav[6];
    for(j=0;j<6;j++) netav[j] = (m1[j]+m2[j])/2;

    free(m1);
    free(m2);
    free(data); //indeed lol

    
    for(j=0;j<6;j++){
        int asnmavg = netav[j];
        char greet[19] = "Net Average  : ";
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

    return 0;
}
