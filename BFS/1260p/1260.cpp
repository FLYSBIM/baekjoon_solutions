#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int graph[1001][1001]={0};
int visited[1001]={0};
int N,M,V;

void bfs(int x){
	queue<int>q;
	q.push(x);
	visited[x]=1;
	while(!q.empty()){
		int current=q.front();
		cout<<current<<" ";
		q.pop();
		for(int i=1;i<=N;i++){
			if(!visited[i]&&graph[current][i]==1){
				q.push(i);
				visited[i]=1;
			}
		}
	}
}
void dfs(int x){
	visited[x]=1;
	cout<<x<<" ";
	for(int i=1;i<=N;i++){
		if(!visited[i]&&graph[x][i]==1){
			dfs(i);
		}
	}
}

int main(void){
	cin>>N>>M>>V;

	for(int i=0;i<M;i++){
		int N1,N2;
		cin>>N1>>N2;
		graph[N1][N2]=1;
		graph[N2][N1]=1;
	}

	dfs(V);
	cout<<endl;
	for(int i=1;i<=N;i++){
		visited[i]=0;
	}
	bfs(V);
	cout<<endl;
}
