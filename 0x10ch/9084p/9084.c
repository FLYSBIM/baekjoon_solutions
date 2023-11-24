#include <stdio.h>

int main(void){
	int T=0;
	scanf("%d",&T);

	int coins[21]={0};
	for(int i=0;i<T;i++){
		int dp[10001]={0};
		dp[0]=1;

		int coin=0;
		int M=0;

		scanf("%d",&coin);
		for(int j=1;j<=coin;j++){
			scanf("%d",&coins[j]);
		}
		scanf("%d",&M);
		for(int k=1;k<=coin;k++){
			for(int j=1;j<=M;j++){
				if(j-coins[k]>=0){
					dp[j]=dp[j]+dp[j-coins[k]];
				}
			}
		}
		printf("%d\n",dp[M]);
	}
}

