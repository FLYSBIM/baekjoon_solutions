#include <stdio.h>

int map[1000][1000]={0};
int visited[1000][1000]={0};
int N,M;

int max(int a,int b){
	return a>b?a:b;
}

int isone(int x,int y){
	int area=1;
	if(x+1<M&&map[y][x+1]==1){
		area+=map[y][x+1];
	}

	if(y+1<N&&map[y+1][x]==1){
                area+=map[y+1][x];
        }

	if(x-1>=0&&map[y][x-1]==1){
                area+=map[y][x-1];
        }
	
	if(y-1>=0&&map[y-1][x]==1){
                area+=map[y-1][x];
        }
	return area;
}

int dfs(int x,int y){
	if(x<0||x>=M||y<0||y>=N||map[y][x]==0||visited[y][x]==1){
		return 0;
	}
	visited[y][x]=1;
	int area=1;

	area+=dfs(x+1,y);
	area+=dfs(x-1,y);
	area+=dfs(x,y-1);
	area+=dfs(x,y+1);
	
	return area;
}

int dfss(int x,int y,int size){
	if(x<0||x>=M||y<0||y>=N||map[y][x]==0||visited[y][x]==2){
		return 0;
	}
	visited[y][x]=2;

	map[y][x]=size;
	
	dfss(x+1,y,size);
	dfss(x-1,y,size);
	dfss(x,y+1,size);
	dfss(x,y-1,size);
	return 0;
}

int main(void){
	scanf("%d%d",&N,&M);

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&map[i][j]);
		}
	}
	int maxarea=0;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]==1&&visited[i][j]==0){
				int size=dfs(j,i);
				dfss(j,i,size);
			}
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]==0){
				maxarea=max(isone(j,i),maxarea);
			}
		}
	}
	printf("%d\n",maxarea);
}
				
	
