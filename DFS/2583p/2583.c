#include <stdio.h>

int map[100][100]={0};
int visited[100][100]={0};
int M,N,K;

int dfs(int x,int y){
	if(x<0||x>=N||y<0||y>=M||map[y][x]==1||visited[y][x]==1){
		return 0;
	}
		
	visited[y][x]=1;
	
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);

	return 0;
}

int main(void){
	scanf("%d%d%d",&M,&N,&K);
	for(int i=0;i<K;i++){
		int x1=0,y1=0,x2=0,y2=0;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(int j=y1;j<=y2;j++){
			for(int k=x1;k<=x2;k++){
				map[j][k]=1;
			}
		}
	}
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			printf("%d",map[i][j]);
		}
		printf("\n");
	}
	int sol=0;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(visited[j][i]==0&&map[j][i]==0){
				dfs(j,i);
				sol++;
			}
		}
	}
	printf("%d\n",sol);
}
	
