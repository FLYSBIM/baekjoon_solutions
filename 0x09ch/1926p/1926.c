#include <stdio.h>

int map[500][500]={0};
int visited[500][500]={0};
int n,m;

int max(int a,int b){
	return a>b?a:b;
}

int dfs(int x,int y){
	if(x<0||x>=m||y<0||y>=n||visited[y][x]==1||map[y][x]==0){
		return 0;
	}
	visited[y][x]=1;
	int area=1;
	
	area+=dfs(x+1,y);
	area+=dfs(x,y+1);
	area+=dfs(x,y-1);
	area+=dfs(x-1,y);
	
	return area;
}

int main(void){
	scanf("%d%d",&n,&m);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&map[i][j]);
		}
	}

	int answer=0;
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==1&&visited[i][j]==0){
				answer=max(answer,dfs(j,i));
				count++;
			}
		}
	}
	printf("%d\n",count);
	printf("%d\n",answer);
}
