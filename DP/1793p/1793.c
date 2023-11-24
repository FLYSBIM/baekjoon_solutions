#include <stdio.h>

int main(void){
	int n=0;
	scanf("%d",&n);

	unsigned long long dp[251]={0};
	

	dp[1]=1;
	dp[2]=3;
	for(int i=3;i<=250;i++){
		dp[i]=dp[i-1]+2*dp[i-2];
	}

	printf("%lld\n",dp[n]);
}
	
