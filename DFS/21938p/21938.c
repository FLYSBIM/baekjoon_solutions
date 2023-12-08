#include <stdio.h>

int map[1000][1000]={0};
int visited[1000][1000]={0};
int N,M;

int dfs(int x,int y,int T){
	if(x<0||x>=M||y<0||y>=N||map[y][x]<T||visited[y][x]==1){
		return 0;
	}

	visited[y][x]=1;

	dfs(x+1,y,T);
	dfs(x-1,y,T);
	dfs(x,y-1,T);
	dfs(x,y+1,T);

	return 0;
}

int main(void){
	int T=0;
	scanf("%d%d",&N,&M);
	int a,b,c;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d%d%d",&a,&b,&c);
			map[i][j]=(a+b+c)/3;
		}
	}
	scanf("%d",&T);

	int count=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(visited[i][j]==0&&map[i][j]>=T){
				dfs(j,i,T);
				count++;
			}
		}
	}
	printf("%d\n",count);
}		
