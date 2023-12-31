#include <stdio.h>

int main(void){

	int N=0;
	scanf("%d",&N);
	
	long dp[91][2]={0};
	
	dp[1][0]=0;
	dp[1][1]=1;
	dp[2][0]=1;
	dp[2][1]=0;
	dp[3][0]=1;
	dp[3][1]=1;
	
	for(int i=4;i<=N;i++){
		dp[i][0]=dp[i-1][0]+dp[i-1][1];
		dp[i][1]=dp[i-1][0];
	}

	printf("%ld\n",dp[N][0]+dp[N][1]);
}
