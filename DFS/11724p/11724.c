#include <stdio.h>

int graph[1001][1001]={0};
int visited[1001]={0};
int N;
void dfs(int x){
	visited[x]=1;

	for(int i=1;i<=N;i++){
		if(graph[x][i]&&visited[i]==0){
			dfs(i);
		}
	}
}

int main(void){
	int M=0;
	scanf("%d%d",&N,&M);
	
	for(int i=0;i<M;i++){
		int a=0,b=0;
		scanf("%d%d",&a,&b);
		graph[a][b]=1;
		graph[b][a]=1;
	}

	int count=0;
	for(int i=1;i<=N;i++){
		if(visited[i]==0){
			dfs(i);
			count++;
		}
	}
	printf("%d\n",count);			
}
