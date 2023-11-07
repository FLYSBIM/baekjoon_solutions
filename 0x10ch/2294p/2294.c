#include <stdio.h>

int main(void){
	int n=0;
	int k=0;
	scanf("%d %d",&n,&k);
	
	int coin[101]={0};
	int dp[10001]={0};

	for(int i=1;i<=n;i++){
		scanf("%d",&coin[i]);
		if(coin[i]<=k){
			dp[coin[i]]=1;
		}
	}

	for(int i=1;i<=k;i++){
		int small=10001;
		for(int j=1;j<=n;j++){
			if(i-coin[j]>=1&&small>dp[i-coin[j]]&&dp[i]!=1&&coin[j]<=k&&dp[i-coin[j]]!=0){
				small=dp[i-coin[j]];
			}
		}
		if(small!=10001){
			dp[i]=small+1;
		}
	}
	
	if(dp[k]==0){
		printf("-1\n");
	}
	else{
		printf("%d\n",dp[k]);
	}
}
		
		
