#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int tmpmap[20][20];
int map[20][20];
int visited[20][20];
int N,M;
vector<pair<int,int> >able;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int sol=0;

int isval(int x,int y){
	return x>=0&&x<M&&y>=0&&y<N;
}

int fron(int x,int y){
	for(int i=0;i<4;i++){
		int nx=dx[i]+x;
		int ny=dy[i]+y;
		if(isval(nx,ny)&&map[ny][nx]==2){
			return 1;
		}
	}
	return 0;
}

int bfs(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			tmpmap[i][j]=map[i][j];
			visited[i][j]=0;
		}
	}
	int area=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(tmpmap[i][j]==2&&!visited[i][j]){
				queue<pair<int,int> >q;
				q.push(make_pair(j,i));
				visited[i][j]=1;
				
				int tarea=1;
				int toggle=0;
				while(!q.empty()){
					pair<int,int>current=q.front();
					q.pop();
					
					for(int k=0;k<4;k++){
						int nx=dx[k]+current.first;
						int ny=dy[k]+current.second;
					
						if(isval(nx,ny)&&!visited[ny][nx]&&tmpmap[ny][nx]==2){
							q.push(make_pair(nx,ny));
							visited[ny][nx]=1;
							tarea++;
						}
						else if(isval(nx,ny)&&tmpmap[ny][nx]==0){
							tarea=0;
							toggle=1;
						}
					}
				}
				if(toggle){
					tarea=0;
				}
				area+=tarea;
			}
		}
	}
	return area;
}
							
void baduk(int k,int idx){
	if(k==2){
		int tmpsol=bfs();
		sol=max(sol,tmpsol);
		return ;
	}

	for(int i=idx;i<able.size();i++){
		map[able[i].second][able[i].first]=1;
		baduk(k+1,i+1);
		map[able[i].second][able[i].first]=0;
	}
}

int main(void){
	cin>>N>>M;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
		}	
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]==0&&fron(j,i)){
                                able.push_back(make_pair(j,i));
                        }
		}
	}
	if(able.size()<2){
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(map[i][j]==0){
					able.push_back(make_pair(j,i));
				}
			}
		}
	}
	baduk(0,0);
	cout<<sol<<endl;
}
