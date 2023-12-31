#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
	return a<b?b:a;
}

int main(void){
	int n=0;
	scanf("%d",&n);
	int*arr=(int*)malloc(sizeof(int)*n);
	int*dp=(int*)malloc(sizeof(int)*n);

	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}

	dp[0]=arr[0];
	dp[1]=arr[0]+arr[1];
	dp[2]=max(max(arr[0]+arr[2],arr[1]+arr[2]),arr[0]+arr[1]);
	
	for(int i=3;i<n;i++){
		dp[i]=max(max(dp[i-2]+arr[i],dp[i-3]+arr[i-1]+arr[i]),dp[i-1]);
	}

	int sol=dp[0];
	for(int i=1;i<n;i++){
		sol=max(sol,dp[i]);
	}
	printf("%d\n",sol);
	free(dp);
	free(arr);
}
