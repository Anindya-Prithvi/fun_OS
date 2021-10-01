#include<stdio.h>

main(int argc, char *argv[]){
        FILE *fp;
        void filecopy(FILE *, FILE *);

        if (argc == 1) filecopy(stdin, stdout);
        else
                while (--argc > 0)
                        if ((fp = fopen(*++argv, "rb"))==NULL){
                                printf("lol idiot");
                        } else {
                                filecopy(fp, stdout);
                                fclose(fp);
                        }
}

void filecopy(FILE *ifp, FILE *ofp){
        char c;
        while((c=getc(ifp))!=EOF)
                putc(c, ofp);
}