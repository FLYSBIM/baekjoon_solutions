#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map₩[1000][1000];
int visited[1000][1000];
int N,M;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int toggle=1;

int bfs(){
	queue<pair<int,int> >q;
	pair<int,int>start=make_pair(0,0);
	pair<int,int>end=make_pair(N-1,M-1);
	q.push(start);
	visited[start.second][start.first]=1;
	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();
		if(current.first==end.first&&current.second==end.second){
			return visited[current.second][current.first]-1;
		}
		for(int i=0;i<4;i++){
			int nx=dx[i]+current.first;
			int ny=dy[i]+current.second;
			
			if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[ny][nx]=='0'&&!visited[ny][nx]){
				q.push(make_pair(nx,ny));
				visited[ny][nx]=visited[current.second][current.first]+1;
			}
		}
	}
	return 0;
}

int main(void){
	cin>>N>>M;

	for(int i=0;i<N;i++){
		cin>>map[i];
	}

	int sol=bfs();
	
	
	if(sol==0){
		cout<<"-1"<<endl;
	}
	else{
		cout<<sol<<endl;
	}
}
