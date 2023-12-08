#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char map[100][100];
int visited[100][100];
int N,M;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int bfs(int x,int y){
	pair<int,int>start=make_pair(x,y);
	queue<pair<int,int> >q;
	q.push(start);
	visited[y][x]=1;
	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();		

		for(int i=0;i<4;i++){
			int nx=current.first+dx[i];
			int ny=current.second+dy[i];
			if(nx>=0&&nx<M&&ny>=0&&ny<N&&!visited[ny][nx]&&map[ny][nx]=='1'){
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

	bfs(0,0);

	printf("%d\n",visited[N-1][M-1]);
}
