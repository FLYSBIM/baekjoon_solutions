#include <iostream>

using namespace std;

int visited[101];
int graph[101][101];
int n;
int x,y;
int a,b;
int sol=-1;

int dfs(int x,int depth){
	visited[x]=1;
	
	if(x==b){
		sol=depth;
	}
	
	for(int i=1;i<=n;i++){
		if(!visited[i]&&graph[i][x]==1){
			dfs(i,depth+1);
		}
	}
	return 1;
}

int main(void){
	cin>>n;

	cin>>a>>b;


	int co;
	cin>>co;

	for(int i=0;i<co;i++){
		cin>>x>>y;
		graph[x][y]=1;
		graph[y][x]=1;
	}

	dfs(a,0);

	cout<<sol<<endl;
}
