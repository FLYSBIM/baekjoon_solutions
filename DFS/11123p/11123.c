#include <stdio.h>

char map[100][100];
int visited[100][100];
int H,W;

int dfs(int x,int y){
	if(x<0||x>=W||y<0||y>=H||map[y][x]=='.'||visited[y][x]==1){
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
		scanf("%d%d",&H,&W);

		for(int j=0;j<H;j++){
			scanf("%s",map[j]);
		}
		
		int count=0;
		for(int j=0;j<H;j++){
			for(int k=0;k<W;k++){
				if(visited[j][k]==0&&map[j][k]=='#'){
					dfs(k,j);
					count++;
				}
			}
		}
		printf("%d\n",count);

		for(int j=0;j<H;j++){
			for(int k=0;k<W;k++){
				visited[j][k]=0;
			}
		}
	}
}
	
