#include <stdio.h>

int max(int a,int b){
	return a>b?a:b;
}

int main(void){
	int n=0;
	scanf("%d",&n);
	
	int box[1001]={0};
	int dp[1001];
	for(int i=1;i<=1000;i++){
		dp[i]=1;
	}

	for(int i=1;i<=n;i++){
		scanf("%d",&box[i]);
	}

	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(box[j]<box[i]){
				dp[i]=max(1+dp[j],dp[i]);
			}
		}
	}
	int sol=dp[1];
	for(int i=2;i<=n;i++){
		sol=max(sol,dp[i]);
	}
	printf("%d\n",sol);
}
				
