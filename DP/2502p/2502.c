#include <stdio.h>

int main(void){
	int dp[31]={0};
	int D,K;

	scanf("%d%d",&D,&K);

	dp[D]=K;

	for(int i=K-1;i>0;i--){
		dp[D-1]=i;
		for(int j=D-2;j>=1;j--){
			dp[j]=dp[j+2]-dp[j+1];
		}
		if(dp[1]<=dp[2]&&dp[1]>0){
			printf("%d\n%d\n",dp[1],dp[2]);
			return 0;
		}
	}
}	
