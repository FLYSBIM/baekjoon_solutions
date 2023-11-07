#include <stdio.h>

int main(void){
	int T=0;
	int N=0;
	scanf("%d",&T);
	
	long dp[101]={0};
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	dp[4]=2;

	for(int i=5;i<=100;i++){
		dp[i]=dp[i-1]+dp[i-5];
	}
	
	for(int i=0;i<T;i++){
		scanf("%d",&N);
		printf("%ld\n",dp[N]);
	}
}
