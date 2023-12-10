#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[200][200]={0};
int visited[200][200]={0};
int N,K;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int S,X,Y;
int bfs(){
	queue<pair<int,int> >V;
	for(int i=1;i<=K;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				if(map[j][k]==i){
					V.push(make_pair(k,j));
					visited[j][k]=1;
				}
			}
		}
	}
	while(!V.empty()&&S!=0){
		int Vsize=V.size();
		for(int j=0;j<Vsize;j++){
			pair<int,int>current=V.front();
			V.pop();
			for(int i=0;i<4;i++){
				int nx=dx[i]+current.first;
				int ny=dy[i]+current.second;
	
				if(nx>=0&&nx<N&&ny>=0&&ny<N&&map[ny][nx]==0&&!visited[ny][nx]){
					V.push(make_pair(nx,ny));
					visited[ny][nx]=1;
					map[ny][nx]=map[current.second][current.first];
				}
			}
		}
		S--;
	}
	return 0;				
}

int main(void){
	cin>>N>>K;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>map[i][j];
		}
	}
	
	cin>>S>>X>>Y;
	bfs();
	if(map[X-1][Y-1]==0){
		cout<<0<<endl;
	}
	else{
		cout<<map[X-1][Y-1]<<endl;
	}
}
