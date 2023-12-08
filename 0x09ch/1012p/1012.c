#include <stdio.h>

int map[50][50]={0};
int visited[50][50]={0};
int M;
int N;
int dfs(int x,int y){
	if(x<0||x>=M||y<0||y>=N||visited[y][x]==1||map[y][x]==0){
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
	int T=0;
	scanf("%d",&T);

	for(int i=0;i<T;i++){
		int K=0;
		scanf("%d%d%d",&M,&N,&K);
		for(int j=0;j<50;j++){
			for(int k=0;k<50;k++){
				map[j][k]=0;
				visited[j][k]=0;
			}
		}

		for(int j=0;j<K;j++){
			int x=0,y=0;
			scanf("%d%d",&x,&y);
			map[y][x]=1;
		}

		int count=0;
		for(int j=0;j<N;j++){
			for(int k=0;k<M;k++){
				if(map[j][k]==1&&visited[j][k]==0){
					dfs(k,j);
					count++;
				}
			}
		}
		printf("%d\n",count);
	}
}
