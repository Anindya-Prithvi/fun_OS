#include<stdio.h>

/*compile as
gcc fwrite.c -o cp.exe
run as (on windows)
cp readfrom writeto
on linux, prefix ./
*/
int main(int argc, char const *argv[])
{
   FILE *sp; //start file
   FILE *dp; //destination
   if(argc!=3){//check if args do not match cp syntax
      printf("Invalid number of arguments: %d \n", argc);
      return 1;
   }
   else{
      char buff[1]; //mono buffer, a larger buffer maybe created
      //but given that the files are "open", I/O speed wont be affected
      sp = fopen(*++argv, "r");//open as read 
      if(sp==NULL){printf("File not readable\n");}
      dp = fopen(*++argv, "w");//open as write/create mode
      if(dp==NULL){printf("No write permissions in directory\n");}
      while(1){
         if(fread(buff, 1, 1, sp)==1)//fread returns 0 if it couldnt read
            fwrite(buff, 1, 1, dp);
         else{
            break;
         }
      }
      printf("Successful \\/O\\/\n");//success
      fclose(sp);
      fclose(dp);
   }
}