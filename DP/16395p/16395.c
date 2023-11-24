#include <stdio.h>

int main(void){
	int dp[31][31]={0};
	

	for(int i=1;i<31;i++){
		for(int j=1;j<=i;j++){
			if(j==1 || j==i){
				dp[i][j]=1;
			}
			else{
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
			}
		}
	}

	int n=0,k=0;
	scanf("%d%d",&n,&k);

	printf("%d\n",dp[n][k]);
}
