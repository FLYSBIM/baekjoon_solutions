#include <stdio.h>

int map[250][250]={0};
int visited[250][250]={0};
int M,N;

int DFS(int x,int y){
	if(x<0||x>=N||y<0||y>=M||visited[y][x]==1||map[y][x]==0){
		return 0;
	}
	visited[y][x]=1;
	DFS(x,y+1);
	DFS(x,y-1);
	DFS(x-1,y);
	DFS(x+1,y);
	DFS(x+1,y+1);
	DFS(x+1,y-1);
	DFS(x-1,y-1);
	DFS(x-1,y+1);

	return 0;
}

int main(void){
	scanf("%d%d",&M,&N);

	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&map[i][j]);
		}
	}

	int count=0;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(visited[i][j]==0&&map[i][j]==1){
				DFS(j,i);
				count++;
			}
		}
	}
	printf("%d\n",count);
}	
