#include <stdio.h>

int graph[101][101]={0};
int visited[101]={0};
int n;
int a,b;
int chon=0;
int dfs(int x){
	visited[x]=1;
	if(x==b){
		return chon;
	}
	

	for(int i=1;i<=n;i++){
		if(visited[i]==0&&graph[x][i]==1){
			chon++;
			dfs(i);
		}
		
	}
	return 0;
}
	
int main(void){
	scanf("%d",&n);
	scanf("%d%d",&a,&b);
	
	int m=0;
	scanf("%d",&m);
	
	int x,y;
	for(int i=0;i<m;i++){
		scanf("%d%d",&x,&y);
		graph[x][y]=1;
		graph[y][x]=1;
	}
	
	int c=dfs(a);
	if(c==0){
		printf("-1\n");
	}
	else if(c!=0){
		printf("%d\n",c);
	}
}
	
