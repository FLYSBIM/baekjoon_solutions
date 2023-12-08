#include <stdio.h>

int map[300][300]={0};
int map2[300][300]={0};
int visited[300][300]={0};
int N,M;

int dfs(int x,int y){
	if(x<0||x>=M||y<0||y>=N||map[y][x]==0||visited[y][x]==1){
		return 0;
	}
	
	visited[y][x]=1;

	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y-1);
	dfs(x,y+1);
	return 0;	
}

int melt(int x,int y){
	map2[y][x]=map[y][x];
	if(map2[y][x]>=1&&x-1>=0&&map[y][x-1]==0){
		map2[y][x]--;
	}
	
	if(map2[y][x]>=1&&x+1<=M&&map[y][x+1]==0){
		map2[y][x]--;
	}

	if(map2[y][x]>=1&&y-1>=0&&map[y-1][x]==0){
		map2[y][x]--;
	}
	
	if(map2[y][x]>=1&&y+1<=N&&map[y+1][x]==0){
		map2[y][x]--;
	}

	return 0;
}
		 

int main(void){
	scanf("%d%d",&N,&M);

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&map[i][j]);
			map2[i][j]=map[i][j];
		}
	}
	int time=0;
	int count=0;
	while(1){
		count=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				visited[i][j]=0;
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				melt(j,i);
			}
		}
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				map[i][j]=map2[i][j];
			}
		}
		time++;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(visited[i][j]==0&&map[i][j]!=0){
					dfs(j,i);
					count++;
				}
			}
		}
		if(count>=2){
			printf("%d\n",time);
			return 0;
		}
		else if(count==0){
			printf("0\n");
			return 0;
		}
	}
}
