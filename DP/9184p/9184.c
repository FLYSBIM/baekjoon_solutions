#include <stdio.h>

char map[500][500]={0};
int visited[500][500]={0};
int dp[500][500]={0};
int N,M;
int out=0;
int f=0;
int dfs(int x,int y,char c){

	if(visited[y][x]==1){
		f++;
		return 0;
	}

	visited[y][x]=1;
	if(c=='R'){
		if(x+1<M){
			dfs(x+1,y,map[y][x+1]);
		}
		else if(x+1>=M){
			out++;
			return 0;
		}
	}
	else if(c=='L'){
		if(x-1>=0){
			dfs(x-1,y,map[y][x-1]);
		}
		else if(x-1<0){
			out++;
		}
	}
	else if(c=='U'){
		if(y+1<N){
			dfs(x,y+1,map[y+1][x]);
		}
		else if(y+1>=N){
			out++;
		}
	}
	else if(c=='D'){
		if(y-1>=0){
			dfs(x,y-1,map[y-1][x]);
		}
		else if(y-1<0){
			out++;
		}
	}
	return 0;
}

int main(void){
	scanf("%d%d",&N,&M);

	for(int i=0;i<N;i++){
		scanf("%s",map[i]);
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<N;k++){
				for(int l=0;l<M;l++){
					visited[k][l]=0;
				}
			}
			if(visited[i][j]==0){
				dfs(j,i,map[i][j]);
			}
		}
	}
	printf("%d\n",out);
}
