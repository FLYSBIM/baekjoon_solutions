#include <stdio.h>

int main(void){

	int dp[101][101]={0};
	int jump[101][101]={0};
	int N=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&jump[i][j]);
		}
	}
	
	dp[0][0]=1;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==N-1&&j==N-1){
				break;
			}

			if(jump[i][j]+j<N){
				dp[i][j+jump[i][j]]+=dp[i][j];
			}
			
			if(jump[i][j]+i<N){
				dp[i+jump[i][j]][j]+=dp[i][j];
			}
		}
	}
	printf("%d\n",dp[N-1][N-1]);
}
