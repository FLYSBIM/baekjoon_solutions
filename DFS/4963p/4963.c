#include <stdio.h>

int map[50][50]={0};
int visited[50][50]={0};
int w=1,h=1;

int dfs(int x,int y){
	if(x<0||x>=w||y<0||y>=h||visited[y][x]==1||map[y][x]==0){
		return 0;
	}
	
	visited[y][x]=1;
	
	dfs(x+1,y+1);
	dfs(x+1,y);
	dfs(x+1,y-1);
	dfs(x-1,y+1);
	dfs(x-1,y-1);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
	
	return 0;
}

int main(void){
	while(w!=0&&h!=0){
		int count=0;
		
		for(int i=0;i<50;i++){
			for(int j=0;j<50;j++){
				map[i][j]=0;
				visited[i][j]=0;
			}
		}
			
		scanf("%d%d",&w,&h);
		if(w==0&&h==0){
			break;
		}
		
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				scanf("%d",&map[i][j]);
			}
		}

		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(visited[i][j]==0&&map[i][j]==1){
					dfs(j,i);
					count++;
				}
			}
		}
		printf("%d\n",count);
	}
}
