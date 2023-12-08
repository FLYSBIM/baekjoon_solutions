#include <stdio.h>

int visited[100][100]={0};
int map[100][100]={0};
int N;

int max(int a,int b){
	return a>b?a:b;
}

int dfs(int x,int y,int height){
	if(x<0||x>=N||y<0||y>=N||map[y][x]<=height||visited[y][x]==1){
		return 0;
	}
	
	visited[y][x]=1;

	dfs(x+1,y,height);
	dfs(x-1,y,height);
	dfs(x,y+1,height);
	dfs(x,y-1,height);

	return 0;
}

int main(void){
	scanf("%d",&N);
	
	int maxval=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&map[i][j]);
			maxval=max(maxval,map[i][j]);
		}
	}

	int sol=0;
	for(int k=0;k<=maxval;k++){
		int count=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(visited[i][j]==0&&map[i][j]>k){
					dfs(j,i,k);
					count++;
				}
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				visited[i][j]=0;
			}
		}
		sol=max(sol,count);
	}
	printf("%d\n",sol);
}	
