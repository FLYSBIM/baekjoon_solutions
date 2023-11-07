#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
	return a>b?a:b;
}

int main(void){
	int N=0;
	int M=0;
	scanf("%d %d",&N,&M);

	int**dp=(int**)malloc(sizeof(int*)*N);
	
	for(int i=0;i<M;i++){
		dp[i]=(int*)malloc(sizeof(int)*M);
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&dp[i][j]);
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(i==0&&j==0){
				continue;
			}
			else if(i==0&&j!=0){
				dp[i][j]+=dp[i][j-1];
			}
			else if(i!=0&&j==0){
				dp[i][j]+=dp[i-1][j];
			}
			else if(i!=0&&j!=0){
				dp[i][j]+=max(max(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]);
			}
		}
	}
	
	printf("%d\n",dp[N-1][M-1]);

	for(int i=0;i<M;i++){
		free(dp[i]);
	}
	free(dp);
}
