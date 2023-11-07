#include <stdio.h>
#include <stdlib.h>

int main(void){
	int T=0;
	int N=0;
	int M=0;
	scanf("%d",&T);


	for(int i=0;i<T;i++){
		int dp[10001]={0};
		scanf("%d",&N);	

		int*coin=(int*)malloc(sizeof(int)*N);
		
		for(int j=0;j<N;j++){
			scanf("%d",&coin[j]);
		}
		
		scanf("%d",&M);
	
		for(int j=0;j<=M;j++){
			for(int k=0;k<N;k++){
				if(dp[j]!=0&&j+coin[k]<=M){
					dp[j+coin[k]]+=1;
				}	

				if(j+coin[k]<=M&&j==0){
					dp[j+coin[k]]+=1;
				}
			}
		}
		for(int i=0;i<=M;i++){
			printf("%d ",dp[i]);
		}
		free(coin);
	}
}
