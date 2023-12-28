#include <iostream>
#include <vector>

using namespace std;

vector<int>graph[2001];
int visited[2001];
int N,M;
int sol=0;
void dfs(int x,int k){
	if(k==4){
		sol=1;
		return ;
	}
	visited[x]=1;
	for(int j=0;j<graph[x].size();j++){
		int i=graph[x][j];
		if(!visited[i]){
			dfs(i,k+1);
		}
	}
	visited[x]=0;			
}

int main(void){
	cin>>N>>M;

	int a,b;
	for(int i=0;i<M;i++){
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	for(int i=0;i<N;i++){
		dfs(i,0);
		if(sol==1){
			cout<<1<<endl;
			return 0;
		}
	}
	cout<<sol<<endl;
}
