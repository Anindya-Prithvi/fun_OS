//goto labels looping
#include <stdio.h>
#pragma GCC optimize("Ofast")

int main(){
	int i = 10;
	int sum = 0;
	label1:
		if(i==0) goto end;
		sum+=i;
		i--;
		goto label1;
	end:
		printf("%d", sum);

}