#include <stdio.h>

int max(int a,int b){
	return a>b?a:b;
}

int main(void){
	int N=0;
	scanf("%d",&N);

	int dp[N+1];
	int cdp[N+1];	
	int ddp[N+1];
	for(int i=1;i<=N;i++){
		scanf("%d",&dp[i]);
		cdp[i]=dp[i];
		ddp[i]=dp[i];
	}

	for(int i=2;i<=N;i++){
		for(int j=i-1;j>0;j--){
			dp[i]=max(dp[i],ddp[i]+cdp[j]);
		}
		for(int k=1;k<i;k++){
			cdp[k]+=cdp[i];
		}
	}

	int sol=dp[1];
	for(int i=1;i<=N;i++){
		printf("%d ",dp[i]);
	}
	printf("\n");
	for(int i=1;i<=N;i++){
                printf("%d ",cdp[i]);
        }

}

	
