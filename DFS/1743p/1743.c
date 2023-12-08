#include <stdio.h>

int map[101][101]={0};
int visited[101][101]={0};
int N,M,K;

int max(int a,int b){
	return a>b?a:b;
}

int dfs(int x,int y){
	visited[y][x]=1;
	int area=1;
	int dx[]={-1,1,0,0};
	int dy[]={0,0,1,-1};
	for(int i=0;i<4;i++){
		int a=x,b=y;
		a+=dx[i];
		b+=dy[i];
		if(a>0&&a<=M&&b>0&&b<=N&&visited[b][a]==0&&map[b][a]==1){
			area+=dfs(a,b);
		}
	}
	return area;
}

int main(void){
	scanf("%d%d%d",&N,&M,&K);

	int x,y;
	for(int i=0;i<K;i++){
		scanf("%d%d",&y,&x);
		map[y][x]=1;
	}

	int maxtrash=0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(visited[i][j]==0&&map[i][j]==1){
				maxtrash=max(maxtrash,dfs(j,i));
			}
		}
	}
	printf("%d\n",maxtrash);
}
