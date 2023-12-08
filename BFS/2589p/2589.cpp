#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[50][50];
int visited[50][50]={0};
int L,W;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void reset_visit(int L,int W){
	for(int i=0;i<L;i++){
		for(int j=0;j<W;j++){
			visited[i][j]=0;
		}
	}
}

int bfs(int x,int y){
	queue<pair<int,int> >q;
	q.push(make_pair(x,y));
	visited[y][x]=1;
	int long_route=0;
	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx=current.first+dx[i];
			int ny=current.second+dy[i];
		
			if(nx>=0&&nx<W&&ny>=0&&ny<L&&map[ny][nx]=='L'&&!visited[ny][nx]){
				q.push(make_pair(nx,ny));
				visited[ny][nx]=visited[current.second][current.first]+1;
				long_route=max(long_route,visited[ny][nx]);
			}
		}
	}
	return long_route-1;
}

int main(void){
	cin>>L>>W;

	for(int i=0;i<L;i++){
		cin>>map[i];
	}
	int lroute=0;
	for(int i=0;i<L;i++){
		for(int j=0;j<W;j++){
			reset_visit(L,W);
			if(map[i][j]=='L'){
				int route=bfs(j,i);
				lroute=max(lroute,route);
			}
		}
	}
	cout<<lroute<<endl;
}	
