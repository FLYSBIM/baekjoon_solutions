#include <stdio.h>

int min(int a,int b){
	return a<b?a:b;
}

int main(void){
	int N=0;
	scanf("%d",&N);

	int home[1001][3]={0};
	int dp[1001][3]={0};
	for(int i=1;i<=N;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&home[i][j]);
		}
	}

	dp[1][0]=home[1][0];
	dp[1][1]=home[1][1];
	dp[1][2]=home[1][2];

	for(int i=2;i<=N;i++){
		dp[i][0]=min(dp[i-1][1]+home[i][0],dp[i-1][2]+home[i][0]);
		dp[i][1]=min(dp[i-1][0]+home[i][1],dp[i-1][2]+home[i][1]);
		dp[i][2]=min(dp[i-1][0]+home[i][2],dp[i-1][1]+home[i][2]);
	}

	printf("%d\n",min(dp[N][0],min(dp[N][1],dp[N][2])));
}
