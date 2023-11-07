#include <stdio.h>

int main(void){
	int T=0;
	scanf("%d",&T);
	
	int fibo[41][2]={0};
	
	fibo[0][0]=1;
	fibo[0][1]=0;
	fibo[1][0]=0;
	fibo[1][1]=1;

	for(int i=2;i<41;i++){
		fibo[i][0]=fibo[i-1][0]+fibo[i-2][0];
		fibo[i][1]=fibo[i-1][1]+fibo[i-2][1];
	}

	int Case=0;
	for(int i=0;i<T;i++){
		scanf("%d",&Case);
		printf("%d %d\n",fibo[Case][0],fibo[Case][1]);
	}
}
	
