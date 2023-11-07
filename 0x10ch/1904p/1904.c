#include <stdio.h>

int main(void){
	long dp[1000001]={0};

	int N=0;
	scanf("%d",&N);

	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=N;i++){
		dp[i]=dp[i-1]%15746+dp[i-2]%15746;
	}

	printf("%ld\n",dp[N]%15746);
}
