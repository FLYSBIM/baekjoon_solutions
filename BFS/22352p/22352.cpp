#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map1[30][30];
int map2[30][30];
int visited[30][30];
int N,M;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int bfs(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map1[i][j]!=map2[i][j]){
				int origin=map1[i][j];
				int up=map2[i][j];
				queue<pair<int,int> >q;
				q.push(make_pair(j,i));
				map1[i][j]=up;
				while(!q.empty()){
					pair<int,int>current=q.front();
					q.pop();
					for(int i=0;i<4;i++){
						int nx=current.first+dx[i];
						int ny=current.second+dy[i];
						
						if(nx>=0&&nx<M&&ny>=0&&ny<N&&map1[ny][nx]==origin){
							q.push(make_pair(nx,ny));
							visited[ny][nx]=1;
							map1[ny][nx]=up;
						}
					}
				}
				return 1;
			}
		}
	}
	return 1;
}

int main(void){
	cin>>N>>M;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map1[i][j];
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map2[i][j];
		}
	}

	bfs();
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map1[i][j]!=map2[i][j]){
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}	
	cout<<"YES"<<endl;
}
