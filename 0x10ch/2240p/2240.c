#include <stdio.h>

int main(void){
	int T=0;
	int W=0;
	scanf("%d %d",&T,&W);
	dp[1001]={0};


	int *arr=(int*)malloc(sizeof(int)*(T+1));

	for(int i=1;i<=T;i++){
		scanf("%d",&arr[i]);
	}

	dp[0]=0;
	for(int i=0;i<T;i++){
