#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
	return a>b?a:b;
}

int main(void){
	int N=0;
	scanf("%d",&N);
	int *card=(int*)malloc(sizeof(int)*(N+1));
	int *dp=(int*)malloc(sizeof(int)*(N+1));
	for(int i=1;i<=N;i++){
		scanf("%d",&card[i]);
		dp[i]=0;
	}

	dp[0]=0;	
	dp[1]=card[1];
	dp[2]=max(2*card[1],card[2]);
	for(int i=3;i<=N;i++){
		int summax=0;
		for(int j=0;j<=i/2;j++){
			if(i-j!=i){
				summax=max(summax,dp[j]+dp[i-j]);
			}
			else{
				summax=max(summax,dp[j]+card[i-j]);
			}
		}
		dp[i]=summax;
	}
	
	printf("%d\n",dp[N]);
	
	free(dp);
	free(card);
}
