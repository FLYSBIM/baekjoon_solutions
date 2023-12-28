#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[100][70];
int visited[100][70];
int N,M;
int dx[8]={1,1,1,0,0,-1,-1,-1};
int dy[8]={1,0,-1,1,-1,1,0,-1};

int bfs(int x,int y){
	int high=1;
	queue<pair<int,int> >q;
	q.push(make_pair(x,y));
	visited[y][x]=1;

	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();

		for(int i=0;i<8;i++){
			int nx=dx[i]+current.first;
			int ny=dy[i]+current.second;
			
			if(nx>=0&&nx<M&&ny>=0&&ny<N){
				if(map[ny][nx]==map[current.second][current.first]&&!visited[ny][nx]){
					visited[ny][nx]=1;
					q.push(make_pair(nx,ny));
				}
				else if(map[ny][nx]>map[current.second][current.first]){
					high=0;
				}
			}
		}
	}
	return high;
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
			if(!visited[i][j]){
				sol+=bfs(j,i);
			}
		}
	}
	cout<<sol<<endl;
}	
