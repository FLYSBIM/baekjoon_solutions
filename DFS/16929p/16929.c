#include <stdio.h>

char map[50][50];
int visited[50][50]={0};
int N,M;
int cycle=0;
int startx,starty;
int toggle=0;
int dfs(int x,int y,char al){
	if(x<0||x>=M||y<0||y>=N||map[y][x]!=al||visited[y][x]==1){
		if((startx==x||starty==y)&&map[y][x]==al){
			cycle=1;
		}
		return 0;
	}

	if(startx==x||starty==y&&visited[y][x]==0){
		toggle++;

	visited[y][x]=1;
	int area=1;

	area+=dfs(x+1,y,map[y][x]);
	area+=dfs(x-1,y,map[y][x]);
	area+=dfs(x,y-1,map[y][x]);
	area+=dfs(x,y+1,map[y][x]);

	if(area>=4&&
	
	toggle=0;
	return area;
}

int main(void){
	scanf("%d%d",&N,&M);

	for(int i=0;i<N;i++){
		scanf("%s",map[i]);
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(visited[i][j]==0){
				startx=j;
				starty=i;
				dfs(j,i,map[i][j]);
			}
			for(int k=0;k<N;k++){
				for(int l=0;l<M;l++){
					visited[k][l]=0;
				}
			}
		}
	}
	if(cycle){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
}
