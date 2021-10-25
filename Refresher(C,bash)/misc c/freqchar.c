#include <stdio.h>
//freq of distinct chars
main(){
	int c, i, j;
	int ascii[128];
	for(i=0; i<128; i++){
		ascii[i]=0;
	}
	while((c=getchar())!=EOF){
		ascii[c]++;
	}
	for(i=0; i<128; i++){
		for(j=0; j<ascii[i]; j++){
			printf(".");
		}
		printf("\n");
	}
}