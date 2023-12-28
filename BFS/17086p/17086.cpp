#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[50][50];
int visited[50][50];
int N,M;
int dx[8]={1,1,1,-1,-1,-1,0,0};
int dy[8]={1,0,-1,1,0,-1,1,-1};

int bfs(int x,int y){
	queue<pair<int,int> >q;
	q.push(make_pair(x,y));
	visited[y][x]=1;
	
	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();
		if(map[current.second][current.first]==1){
			return visited[current.second][current.first]-1;
		}
		for(int i=0;i<8;i++){
			int nx=dx[i]+current.first;
			int ny=dy[i]+current.second;
			
			if(nx>=0&&nx<M&&ny>=0&&ny<N&&!visited[ny][nx]){
				q.push(make_pair(nx,ny));
				visited[ny][nx]=visited[current.second][current.first]+1;
			}
		}
	}
	return 0;
}

void initvisit(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			visited[i][j]=0;
		}
	}
}

int main(void){
	cin>>N>>M;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
		}
	}
	

	int sol=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			sol=max(sol,bfs(j,i));
			initvisit();
		}
	}
	cout<<sol<<endl;
}
		
