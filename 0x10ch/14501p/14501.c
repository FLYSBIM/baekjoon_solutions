#include <stdio.h>

int max(int a,int b){
	return a>b?a:b;
}

int main(void){
	int N=0;
	scanf("%d",&N);
	int arr[16][2]={0};
	int dp[16]={0};
	for(int i=0;i<N;i++){
		for(int j=0;j<2;j++){
			scanf("%d",&arr[i][j]);
		}
	}

	dp[0]=0;
	for(int i=1;i<=N;i++){
		int Max=0;
		int index=0;
		for(int j=i-1;j>=0;j--){
			if(arr[j][0]<=i-j&&Max<arr[j][1]){
				Max=arr[j][1];
				//Max=dp[j];
			}
		}
		dp[i]+=Max;
		arr[i][1]+=dp[i];
	}
	
	int sol=dp[0];	
	for(int i=1;i<=N;i++){
		sol=max(sol,dp[i]);
	}
	printf("%d\n",sol);
}	
