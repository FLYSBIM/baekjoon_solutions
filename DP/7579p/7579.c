#include <stdio.h>

int min(int a,int b){
	return a<b?a:b;
}

int main(void){
	int N=0,M=0;
	scanf("%d%d",&N,&M);

	int memory[101]={0};
	int cost[101]={0}
	
	
	for(int i=1;i<=N;i++){
		scanf("%d",&memory[i]);
	}
	for(int i=1;i<=N;i++){
		scanf("%d",&cost[i]);
	}

	int dp[101][1000000001]={0};


	for(int i=0;i<=N;i++){
		for(int j=0;j<=M;j++){
			if(i==0 || j==0){
				dp[i][j]=0;
			}
			else if(memory[i]<=j){
				dp[i][j]=min(dp[i-1][j],dp[i-1][j-memory[i]]+cost[i]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	
	int sol=dp[i][j];
	
	for(int i=0;i<=N;i++){
		for(int j=0;j<=M;j++){
			if(sol
}
