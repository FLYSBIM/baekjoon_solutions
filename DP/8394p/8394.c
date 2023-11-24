#include <stdio.h>

int main(void){
	int n=0;
	scanf("%d",&n);

	unsigned long long dp[10000001]={0};

	dp[1]=1;
	dp[2]=2ULL;
	
	for(int i=3;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}

	printf("%lld\n",dp[n]);
}
