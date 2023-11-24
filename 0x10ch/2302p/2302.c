#include <stdio.h>

int main(void){
	int N=0,M=0;
	scanf("%d%d",&N,&M);

	int dp[41]={0};
	dp[0]=1;
	dp[1]=1;
	int fixed[41]={0};

	int fix=0;
	for(int i=0;i<M;i++){
		scanf("%d",&fix);
		fixed[fix]=1;
	}

	for(int i=2;i<=N;i++){
		if(fixed[i]==1){
			dp[i]=dp[i-1];
		}
		else if(fixed[i-1]==1){
			dp[i]=dp[i-1];
		}
		else if(fixed[i]!=1){
			dp[i]=dp[i-1]+dp[i-2];
		}	
	}
	printf("%d\n",dp[N]);			
}
	
