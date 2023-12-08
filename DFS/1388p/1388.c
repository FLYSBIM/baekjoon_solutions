#include <stdio.h>

char map[50][50];
int visited[50][50]={0};
int N,M;
int dfs(int x,int y,char c){
	visited[y][x]=1;

	for(int i=0;i<4;i++){
		int dx[]={-1,1,0,0};
		int dy[]={0,0,1,-1};
		int a=x,b=y;
		a+=dx[i];
		b+=dy[i];
		if(a>=0&&a<M&&b>=0&&b<N&&visited[b][a]==0&&c==map[b][a]&&c=='-'&&i>=0&&i<=1){
			dfs(a,b,map[b][a]);
		}
		else if(a>=0&&a<M&&b>=0&&b<N&&visited[b][a]==0&&c==map[b][a]&&c=='|'&&i>=2&&i<=3){
			dfs(a,b,map[b][a]);
		}	
	}
	return 0;
}

int main(void){
	scanf("%d%d",&N,&M);

	for(int i=0;i<N;i++){
		scanf("%s",map[i]);
	}

	int count=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(visited[i][j]==0){
				dfs(j,i,map[i][j]);
				count++;
			}
		}
	}
	printf("%d\n",count);
}
