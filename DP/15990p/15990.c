#include <stdio.h>

int main(void){
	int t=0;
	scanf("%d",&t);


	int dp[100001][4]={0};
	dp[1][1]=1;
	dp[2][2]=1;
	dp[3][1]=1;
	dp[3][2]=1;
	dp[3][3]=1;
	
	for(int i=4;i<=100000;i++){
		dp[i][1]=(dp[i-1][3]+dp[i-1][2])%1000000009;
                dp[i][2]=(dp[i-2][1]+dp[i-2][3])%1000000009;
                dp[i][3]=(dp[i-3][1]+dp[i-3][2])%1000000009;
	}

	int n=0;	
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		printf("%d\n",(dp[n][1]+dp[n][2]+dp[n][3])%1000000009);
	}

}
