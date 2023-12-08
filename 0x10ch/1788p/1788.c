#include <stdio.h>

int main(void){
	int n=0;
	scanf("%d",&n);
	
	if(n<0){
		long dp[10001]={0};

        	dp[0]=1; //n=1
        	dp[1]=0; //n=0
        	for(int i=2;i<=-n+1;i++){
                	dp[i]=(dp[i-2]-dp[i-1])%1000000000;
        	}
		if(dp[-n+1]>0){
			printf("1\n");
		}
		else if(dp[-n+1]<0){
			printf("-1\n");
		}
		printf("%ld\n",dp[-n+1]);
	}
	else if(n>0){
		long dp[10001]={0};
		dp[0]=0;	
		dp[1]=1;
		for(int i=2;i<=n;i++){
			dp[i]=(dp[i-1]+dp[i-2])%1000000000;
		}
		printf("1\n%ld\n",dp[n]);
	}
	else if(n==0){
		printf("0\n0\n");
	}
	
}
