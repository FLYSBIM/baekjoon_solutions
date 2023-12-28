#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[8][8];
int map2[8][8];
int N,M;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int sol=0;
int used[8][8];
int visited[8][8];
int bfs(){
	queue<pair<int,int> >virus;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			visited[i][j]=0;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			map2[i][j]=map[i][j];
			if(map2[i][j]==2){
				virus.push(make_pair(j,i));
				visited[i][j]=1;
			}
		}
	}

	while(!virus.empty()){
		pair<int,int>current=virus.front();
		virus.pop();
		for(int j=0;j<4;j++){
			int nx=dx[j]+current.first;
			int ny=dy[j]+current.second;
				
			if(nx>=0&&nx<M&&ny>=0&&ny<N&&map2[ny][nx]==0&&!visited[ny][nx]){
				virus.push(make_pair(nx,ny));
				map2[ny][nx]=2;
				visited[ny][nx]=1;
			}
		}
	}
	return 1;	
}

void buildwall(int k,int startx,int starty){
	if(k==3){
		bfs();
		int safe_area=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(map2[i][j]==0){
					safe_area++;
				}
			}
		}
		sol=max(sol,safe_area);
		return ;
	}

	for(int i=startx;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]==0){
				map[i][j]=1;
				int nextrow=i;
				int nextcol=j+1;
				if(j+1==M){
					nextrow=i+1;
					nextcol=0;
				}
				buildwall(k+1,nextrow,nextcol);
				map[i][j]=0;
			}
		}
	}
}

int main(void){
	cin>>N>>M;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
		}
	}
	buildwall(0,0,0);	
	cout<<sol<<endl;
}
