#include <stdio.h>

int main(void){
	int n=0;
	scanf("%d",&n);

	long dp[1000001]={0};

	dp[0]=0;
	dp[1]=1;

	if(n>0){
		for(int i=2;i<=n;i++){
			dp[i]=(dp[i-1]+dp[i-2])%1000000000;
		}
		printf("1\n%ld\n",dp[n]);
	}
	else if(n<0){
		dp[1]=1;
		for(int i=-2;i>=n;i--){
			dp[-i]=dp[-i-2]-dp[-i-1];
		}
		printf("-1\n");
		if(dp[-n]<0){
			printf("%ld",-dp[-n]);
		}
		else if(dp[-n]>=0){
			printf("%ld",dp[-n]);
		}
	}
	else if(n==0){
		printf("0\n0\n");
	}
}
