#include <stdio.h>

int main(void){

	long long dp[1001][1001]={0};
	dp[1][1]=1;

	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			if(i==1 || j==1){
				dp[i][j]=1;
			}
			else{
				dp[i][j]=(dp[i-1][j]%1000000007+dp[i][j-1]%1000000007+dp[i-1][j-1]%1000000007)%1000000007;
			}
		}
	}
	int n=0,m=0;
	scanf("%d%d",&n,&m);
	printf("%lld\n",dp[n][m]%1000000007);
}
