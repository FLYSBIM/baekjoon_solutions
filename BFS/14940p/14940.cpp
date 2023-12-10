#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[1000][1000]={0};
int visited[1000][1000]={0};
int n,m;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int bfs(){
	pair<int,int>start;
	queue<pair<int,int> >q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==2){
				start=make_pair(j,i);
				q.push(start);
				visited[i][j]=1;
			}
		}
	}
	
	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx=current.first+dx[i];
			int ny=current.second+dy[i];
			
			if(nx>=0&&nx<m&&ny>=0&&ny<n&&map[ny][nx]==1&&!visited[ny][nx]){
				q.push(make_pair(nx,ny));
				visited[ny][nx]=visited[current.second][current.first]+1;
			}
		}
	}
	return 0;	
}

int main(void){
	cin>>n>>m;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}

	bfs();

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==0){
				cout<<0<<" ";
			}
			else{
				cout<<visited[i][j]-1<<" ";
			}
		}
		cout<<endl;
	}

}
