#include <stdio.h>

int main(void){
	long long maze[16][16]={0};

	int N=0,M=0;
	scanf("%d%d",&N,&M);
	
	int K=0;
	scanf("%d",&K);

	maze[1][1]=1;
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(i==1||j==1){
				maze[i][j]=1;
			}
			else{
				maze[i][j]=maze[i-1][j]+maze[i][j-1];
			}

			if(K==(i-1)*M+j){
				for(int k=i;k<=N;k++){
					for(int l=j;l<=M;l++){
						if(k==i || l==j){
							maze[k][l]=maze[i][j];
						}
						else{
							maze[k][l]=maze[k-1][l]+maze[k][l-1];
						}
					}
				}j
				printf("%lld\n",maze[N][M]);
				return 0;
			}
		}
	}
	if(K==0){
		printf("%lld\n",maze[N][M]);
	}

}

