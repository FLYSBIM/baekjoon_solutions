#include <stdio.h>

int main(void){
	int dp[101][10]={0};
	
	int N=0;
	scanf("%d",&N);

	for(int i=1;i<10;i++){
		dp[1][i]=1;
	}

	for(int i=2;i<=N;i++){
		for(int j=0;j<10;j++){
			if(j==0){
				dp[i][j]=dp[i-1][j+1]%1000000000;
			}
			else if(0<j && j<9){
				dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
			}
			else if(j==9){
				dp[i][j]=dp[i-1][j-1]%1000000000;
			}
		}
	}

	int sol=0;
	for(int i=0;i<10;i++){
		sol+=dp[N][i]%1000000000;
	}
	printf("%d\n",sol%1000000000);
}
