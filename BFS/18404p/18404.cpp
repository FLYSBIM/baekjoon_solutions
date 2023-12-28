#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[501][501];
int visited[501][501];
int dx[8]={1,1,2,2,-1,-1,-2,-2};
int dy[8]={2,-2,1,-1,2,-2,1,-1};
int N,M;

int bfs(int X,int Y){
	queue<pair<int,int> >q;
	q.push(make_pair(X-1,Y-1));
	visited[Y-1][X-1]=1;

	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();

		for(int i=0;i<8;i++){
			int nx=dx[i]+current.first;
			int ny=dy[i]+current.second;
			
			if(nx>=0&&nx<N&&ny>=0&&ny<N&&!visited[ny][nx]){
				visited[ny][nx]=visited[current.second][current.first]+1;
				q.push(make_pair(nx,ny));
			}
		}
	}
	return -1;
}

int main(void){
	cin>>N>>M;
	int X,Y;
	cin>>X>>Y;
	int A,B;
	vector<pair<int,int> >enemy;
	for(int i=0;i<M;i++){
		cin>>A>>B;
		enemy.push_back(make_pair(A-1,B-1));
	}
	bfs(X,Y);
	
	for(int i=0;i<M;i++){
		cout<<visited[enemy[i].second][enemy[i].first]-1<<" ";
	}
	cout<<endl;
}

	
	
