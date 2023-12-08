#include <stdio.h>

char map[1000][1000];
int visited[1000][1000]={0};
int M,N;
int toggle=0;
int dfs(int x,int y){
	if(x<0||x>=N||y<0||y>=M||map[y][x]=='1'||visited[y][x]==1){
		return 0;
	}
	
	if(y==M-1){
		toggle=1;
	}

	visited[y][x]=1;

	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
	

	return 0;
}

int main(void){
	scanf("%d%d",&M,&N);

	for(int i=0;i<M;i++){
		scanf("%s",map[i]);
	}
	

	for(int i=0;i<N;i++){
		if(visited[0][i]==0&&map[0][i]=='0'){
			dfs(i,0);
		}
	}

	if(toggle){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}
