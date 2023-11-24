#include <stdio.h>

int main(void){
	unsigned long long dp[36]={0};

	dp[0]=1;
	dp[1]=1;

	for(int i=2;i<=35;i++){
		for(int j=0;j<i;j++){
			dp[i]+=dp[j]*dp[i-j-1];
		}
	}

	int n=0;
	scanf("%d",&n);
	printf("%lld\n",dp[n]);
}
