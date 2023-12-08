#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[500][500]={0};
int visited[500][500]={0};
int n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int bfs(int x,int y){
	queue<pair<int,int> >q;
	q.push(make_pair(x,y));
	visited[y][x]=1;
	int area=0;
	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();
		area++;
		for(int i=0;i<4;i++){
			int nx=current.first+dx[i];
			int ny=current.second+dy[i];
		
			if(nx>=0&&nx<m&&ny>=0&&ny<n&&!visited[ny][nx]&&map[ny][nx]==1){
				q.push(make_pair(nx,ny));
				visited[ny][nx]=1;
			}
		}
	}
	return area;
}

int main(void){
	cin>>n>>m;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}

	int count=0;
	int big=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==1&&!visited[i][j]){
				int a=bfs(j,i);
				count++;
				big=max(big,a);
			}
		}
	}
	cout<<count<<"\n";
	cout<<big<<"\n";
}
