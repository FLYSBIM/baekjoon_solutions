#include <stdio.h>
#include <stdlib.h>

int min(int a,int b){
	return a<b?a:b;
}

int main(void){
	int X=0;
	scanf("%d",&X);

	int*dp=(int*)malloc(sizeof(int)*(X+1));
	for(int i=0;i<=X;i++){
		dp[i]=0;
	}
	dp[2]=1;
	dp[3]=1;

	
	for(int i=2;i<=X;i++){
		if(i%3==0&&i%2!=0){
			dp[i]=min(dp[i-1]+1,dp[i/3]+1);
		}
		else if(i%2==0&&i%3!=0){
			dp[i]=min(dp[i/2]+1,dp[i-1]+1);
		}
		else if(i%2==0&&i%3==0){
			dp[i]=min(dp[i-1]+1,min(dp[i/2]+1,dp[i/3]+1));
		}
		else{
			dp[i]=dp[i-1]+1;
		}
	}
	printf("%d\n",dp[X]);
	free(dp);
}
