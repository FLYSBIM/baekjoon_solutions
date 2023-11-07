#include <stdio.h>

int main(void){
	int n=0;
	scanf("%d",&n);
	
	long dp[1001]={0};

	dp[1]=1;
	dp[2]=3;
	dp[3]=5;
	
	for(int i=4;i<=n;i++){
		dp[i]=(dp[i-1]+2*dp[i-2])%10007;
	}
	
	printf("%ld\n",dp[n]);
}
