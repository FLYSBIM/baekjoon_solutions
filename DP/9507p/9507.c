#include <stdio.h>

int main(void){
	unsigned long long dp[70]={0};

	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;

	for(int i=4;i<=68;i++){
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4];
	}

	int T=0;
	scanf("%d",&T);

	for(int i=0;i<T;i++){
		int n=0;
		scanf("%d",&n);
		printf("%lld\n",dp[n]);
	}
}
