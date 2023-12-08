#include <stdio.h>

int max(int a,int b){
	return a>b?a:b;
}

int main(void){
	int N=0,S=0,M=0;
	int dp[1001]={0};
	int dp2[10001]={0};
	int V[50]={0};

	scanf("%d%d%d",&N,&S,&M);
	
	for(int i=0;i<N;i++){
		scanf("%d",&V[i]);
	}

	dp[S]=1;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<=M;j++){
			if(dp[j]!=i+2&&dp[j]!=0){
				dp[j]=0;
				if(j+V[i]<=M){
					dp2[j+V[i]]=i+2;
				}

				if(j-V[i]>=0){
					dp2[j-V[i]]=i+2;
				}
				
			}
		}
		for(int j=0;j<=M;j++){
			printf("%d ",dp2[j]);
		}
		printf("\n");
	}

	int sol=-1;
	
	for(int i=0;i<=M;i++){
		if(dp[i]!=0){
			sol=max(sol,i);
		}
	}				
	printf("%d\n",sol);	
}
