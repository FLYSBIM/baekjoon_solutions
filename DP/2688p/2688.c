#include <stdio.h>

int main(void){
	int T=0;
	scanf("%d",&T);

	unsigned long long dp[1001][10]={0};

	for(int i=0;i<10;i++){
		dp[1][i]=1;
	}

	for(int i=2;i<=1000;i++){
		for(int j=0;j<10;j++){
			for(int k=j;k>=0;k--){
				dp[i][j]+=dp[i-1][k];
			}
		}
	}

	for(int i=0;i<T;i++){
		int n=0;
		unsigned long long sol=0;
		scanf("%d",&n);
		for(int j=0;j<10;j++){
			sol+=dp[n][j];
		}
		printf("%lld\n",sol);
	}		
}
