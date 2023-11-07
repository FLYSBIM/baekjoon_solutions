#include <stdio.h>

int min(int a,int b){
	return a<b?a:b;
}

int main(void){
	int dp[100001]={0};
	
	dp[2]=1;
	dp[4]=2;
	dp[6]=3;
	dp[5]=1;
	
	int n=0;
	scanf("%d",&n);
	
	for(int i=7;i<=n;i++){
		if(dp[i-2]>=1 && dp[i-5]>=1){
			dp[i]=min(dp[i-2],dp[i-5])+1;
		}
		else if(dp[i-2]>=1 && dp[i-5]==0){
			dp[i]=dp[i-2]+1;
		}
		else if(dp[i-5]>=1 && dp[i-2]==0){
                        dp[i]=dp[i-5]+1;
                }
	}

	if(dp[n]==0){
		printf("-1\n");
	}
	else{
		printf("%d\n",dp[n]);
	}
}
