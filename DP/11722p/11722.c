#include <stdio.h>

int min(int a,int b){
	return a<b?a:b;
}

int max(int a,int b){
	return a>b?a:b;
}

int main(void){
	int arr[1001]={0};
	int dp[1001]={0};

	int N=0;
	scanf("%d",&N);
	
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
		dp[i]=1;
	}

	for(int i=1;i<N;i++){
		for(int j=i;j>=0;j--){
			if(arr[i]<arr[j]){
				dp[i]=max(1+dp[j],dp[i]);
			}
		}
	}
	
	int sol=dp[0];
	for(int i=0;i<N;i++){
		sol=max(sol,dp[i]);
	}
	printf("%d\n",sol);
}
		
