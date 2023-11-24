#include <stdio.h>

int max(int a,int b){
	return a>b?a:b;
}

int main(void){
	int dp[2][21]={0};

	int n=0;
	scanf("%d",&n);

	for(int i=1;i<=n;i++){
		scanf("%d",&dp[0][i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&dp[1][i]);
	}

	
