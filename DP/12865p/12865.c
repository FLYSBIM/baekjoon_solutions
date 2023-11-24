#include <stdio.h>

int max(int a,int b){
	return a>b?a:b;
}

int main(void){
	int N=0;
	int K=0;
	scanf("%d",&N);
	scanf("%d",&K);

	int dp[N+1][K+1];
	int obj[101][2]={0};

	for(int i=1;i<=N;i++){
		scanf("%d %d",&obj[i][0],&obj[i][1]);
	}	
	for(int i=0;i<=N;i++){
		for(int j=0;j<=K;j++){
			if(i==0||j==0){
				dp[i][j]=0;
			}
			else if(j>=obj[i][0]){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-obj[i][0]]+obj[i][1]);
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	printf("%d\n",dp[N][K]);
}		
		
