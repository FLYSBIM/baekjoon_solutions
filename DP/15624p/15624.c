#include <stdio.h>

int main(void){
	unsigned long long dp[1000001]={0};

	dp[0]=0;
	dp[1]=1;

	int n=0;
	scanf("%d",&n);
	
	for(int i=2;i<=n;i++){
		dp[i]=(dp[i-1]+dp[i-2])%1000000007;
	}

	printf("%lld\n",dp[n]);
}
