#include <stdio.h>

int main(void){
	int N=0;
	scanf("%d",&N);

	long long dp[82]={0};
	dp[1]=1;
	dp[2]=1;
	for(int i=3;i<82;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}

	long long sol=dp[N+1]*2+dp[N]*2;
	printf("%lld\n",sol);
}
