#include <stdio.h>

int min(int a,int b){
	return a<b?a:b;
}

int main(void){
	int card[1001]={0};
	int dp[1001]={0};
	
	int N=0;
	scanf("%d",&N);

	for(int i=1;i<=N;i++){
		scanf("%d",&card[i]);
		dp[i]=card[i];
	}

	dp[1]=card[1];
	dp[2]=min(card[2],2*card[1]);

	for(int i=3;i<=N;i++){
		for(int j=1;j<=i/2;j++){
			if(i-j>=0){
				dp[i]=min(dp[i],min(dp[i-j]+dp[j],card[i]));
			}
		}
	}
	printf("%d\n",dp[N]);
}
