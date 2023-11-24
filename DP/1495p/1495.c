#include <stdio.h>

int max(int a,int b){
	return a>b?a:b;
}

int min(int a,int b){
	return a<b?a:b;
}

int main(void){
	int N=0,S=0,M=0;

	int dp[51][2]={0};

	scanf("%d%d%d",&N,&S,&M);

	dp[0][1]=S;
	dp[0][0]=S;

	for(int i=1;i<=N;i++){
		scanf("%d",&dp[i][0]);
		dp[i][1]=-dp[i][0];
	}

	for(int i=1;i<=N;i++){
		int mm=max(dp[i-1][0],dp[i-1][1]);
		int sm=min(dp[i-1][0],dp[i-1][1]);
		if(mm+dp[i][0]>=0&&mm+dp[i][0]<=M&&mm>=0){
			dp[i][0]+=mm;
		}
		else if(sm+dp[i][0]>=0&&sm+dp[i][0]<=M&&sm>=0){
			dp[i][0]+=sm;
		}
		else{
			dp[i][0]=-1;
		}
		
		if(mm+dp[i][1]>=0&&mm+dp[i][1]<=M&&mm>=0){
			dp[i][1]+=mm;
		}
		else if(sm+dp[i][1]>=0&&sm+dp[i][1]<=M&&sm>=0){
			dp[i][1]+=sm;
		}
		else{
			dp[i][1]=-1;
		}
	}
	for(int i=0;i<=N;i++){
		printf("%d %d\n",dp[i][0],dp[i][1]);
	}
}
