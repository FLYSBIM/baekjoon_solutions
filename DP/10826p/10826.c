#include <stdio.h>

int main(void){
	unsigned long long dp[10001]={0};
	
	dp[0]=0;
	dp[1]=1;

	int n=0;
	scanf("%d",&n);
	
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	printf("%llu\n",dp[n]);
}
