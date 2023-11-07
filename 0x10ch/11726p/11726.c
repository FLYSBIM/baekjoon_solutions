#include <stdio.h>

int main(void){
	int dp[1001]={0};
	int n=0;

	scanf("%d",&n);
	dp[1]=1;
	dp[2]=2;

	for(int i=3;i<=n;i++){
		dp[i]=(dp[i-2]+dp[i-1])%10007;
	}
	
	printf("%d\n",dp[n]);
}
