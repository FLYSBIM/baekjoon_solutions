#include <stdio.h>

char map[600][600];
int visited[600][600]={0};
int N,M;
int fri=0;
int dfs(int x,int y){
	if(x<0||x>=M||y<0||y>=N||map[y][x]=='X'||visited[y][x]==1){
		return 0;
	}
	
	if(map[y][x]=='P'){
		fri++;
	}
	
	visited[y][x]=1;

	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
	
	return 0;
}

int main(void){
	scanf("%d%d",&N,&M);

	for(int i=0;i<N;i++){
		scanf("%s",map[i]);
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]=='I'){
				dfs(j,i);
			}
		}
	}
	if(fri!=0){
		printf("%d\n",fri);
	}
	else{
		printf("TT\n");
	}
}
