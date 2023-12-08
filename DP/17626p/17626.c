#include <stdio.h>

int min(int a,int b){
	return a<b?a:b;
}

int main(void){
	int dp[50001]={0};

	for(int i=1;i<50001;i++){
		dp[i]=500000;
	}

	for(int i=1;i<=223;i++){
		dp[i*i]=1;
	}

	for(int i=2;i<50001;i++){
		for(int j=1;i-j*j>0;j++){
			if(dp[i]!=1){
				dp[i]=min(dp[i],dp[i-j*j]+1);
			}
		}
	}

	int n=0;
	scanf("%d",&n);

	printf("%d\n",dp[n]);
}

