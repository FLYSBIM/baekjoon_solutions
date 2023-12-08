#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[1000][1000]={0};
int visited[1000][1000]={0};
int M,N;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int bfs(){
	queue<pair<int,int> >q;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]==1){
				q.push(make_pair(j,i));
				visited[i][j]=1;
			}
		}
	}
	int time=0;
	while(!q.empty()){
		int csize=q.size();
		for(int i=0;i<csize;i++){
			pair<int,int>current=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int nx=current.first+dx[i];
				int ny=current.second+dy[i];
		
				if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[ny][nx]!=-1&&!visited[ny][nx]){
					q.push(make_pair(nx,ny));
					if(map[ny][nx]==0){
						map[ny][nx]=1;
					}
					visited[ny][nx]=1;
				}
			}
		}
		if(q.empty()){
			return time;
		}
		time++;
	}	
	return time;
}

int main(void){
	scanf("%d%d",&M,&N);

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
		}
	}
	int maxtime=bfs();

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]==0){
				cout<<"-1\n";
				return 0;
			}
		}
	}
	cout<<maxtime<<"\n";
}
