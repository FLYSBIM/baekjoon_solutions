#include <stdio.h>

int main(void){
	int T=0;
	scanf("%d",&T);
	long dp[1000001]={0};

	dp[1]=1;
	dp[2]=2;
	dp[3]=4;

	int n=0;
	for(int i=0;i<T;i++){
		scanf("%d",&n);
		for(int j=4;j<=n;j++){
			dp[j]=(dp[j-1]+dp[j-2]+dp[j-3])%1000000009;
		}
		printf("%ld\n",dp[n]);
	}
}
