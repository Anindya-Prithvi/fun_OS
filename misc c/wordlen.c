#include<stdio.h>

/* word histogram ;*/
#define IN 1	//inside
#define OUT 0	//outside
main()
{
	int lenhist[16]; //assume 1 indexed
	int c, nl, nw, nc, state, i ,j;
	for(i=0; i<16; i++){
		lenhist[i]=0; //initialize
	}
	state = OUT;
	nl = nw = nc = 0;
	while((c=getchar()) != EOF){
		++nc;
		if(c=='\n'){++nl;nc=0;}
		if((c==' ')||(c=='\n')||(c=='\t')){state=OUT;lenhist[nc]++;}
		else if (state==OUT){
			state = IN;
			nc=0;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
	lenhist[0]=0;
	for(i=0; i<16; i++){
		for(j=0; j<lenhist[i]; j++){
			printf(".");
		}
		printf("\n");
	}
}
