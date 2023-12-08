#include <stdio.h>

int graph[101][101]={0};
int visited[101]={0};
int n;

int dfs(int x){
	visited[x]=1;
	for(int i=1;i<n;i++){
		if(graph[x][i]==1&&visited[i]==0){
			dfs(i);
		}
	}

	return 0;
}

int main(void){
	scanf("%d",&n);
	int m=0;
	scanf("%d",&m);

	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a][b]=1;
		graph[b][a]=1;
	}

	dfs(1);
	int sol=0;
	for(int i=2;i<=n;i++){
		if(visited[i]==1){
			sol++;
		}
	}
	printf("%d\n",sol);
}	
		
