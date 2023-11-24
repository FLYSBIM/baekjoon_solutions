#include <stdio.h>

int min(int a,int b){
	return a<b?a:b;
}

int main(void){
	int dp[100001]={0};
	
	for(int i=1;i<100001;i++){
		dp[i]=i;
	}

	int N=0;
	scanf("%d",&N);
	for(int i=4;i<=N;i++){
		for(int j=1;j*j<=i;j++){
			dp[i]=min(dp[i],dp[i-j*j]+1);
		}
	}

	printf("%d\n",dp[N]);
}
