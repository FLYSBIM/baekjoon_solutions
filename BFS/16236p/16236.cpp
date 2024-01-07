#include <iostream>
#include <tuple>
#include <queue>
#include <vector>

using namespace std;

int map[20][20];
int visited[20][20];
int N;
int dx[4]={0,-1,1,0};
int dy[4]={1,0,0,-1};
int nowSize=2;
int noweat=0;

int isval(int x,int y){
	return x>=0&&x<N&&y>=0&&y<N;
}

int bfs(){
	queue<tuple<int,int,int,int> >q;
		
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(map[i][j]==9){
				q.push(make_tuple(j,i,nowSize,noweat));
				visited[i][j]=1;
				map[i][j]=0;
			}
		}
	}	
	int toggle=0;
	int min_dis=100000;
	pair<int,int>dis;
	while(!q.empty()){
		tuple<int,int,int,int>current=q.front();
		q.pop();
		int x=get<0>(current);
		int y=get<1>(current);
		int Size=get<2>(current);
		int eat=get<3>(current);

		for(int i=0;i<4;i++){
			int nx=dx[i]+x;
			int ny=dy[i]+y;
			
			if(isval(nx,ny)&&!visited[ny][nx]&&map[ny][nx]<=Size){
				if(map[ny][nx]==0){
					visited[ny][nx]=visited[y][x]+1;
					q.push(make_tuple(nx,ny,Size,eat));
				}
				else if(map[ny][nx]!=0&&map[ny][nx]<Size){
					visited[ny][nx]=visited[y][x]+1;
					if(min_dis>visited[ny][nx]-1){
						dis.first=nx;
						dis.second=ny;
						min_dis=min(min_dis,visited[ny][nx]-1);
					}
					toggle=1;
					if(min_dis>=visited[ny][nx]-1){
						if(eat+1==Size){
							nowSize=Size+1;
							noweat=0;
						}
						else if(eat+1<Size){
							nowSize=Size;
							noweat=eat+1;
						}
					}
					
					if(min_dis==visited[ny][nx]-1){
						if(ny<dis.second){
							dis.first=nx;
							dis.second=ny;
						}
						else if(ny==dis.second&&nx<dis.first){
							dis.first=nx;
							dis.second=ny;
						}
					}
				}
				else if(map[ny][nx]==Size){
					visited[ny][nx]=visited[y][x]+1;
					q.push(make_tuple(nx,ny,Size,eat));
				}
			}
		}
	}
	if(toggle){
		map[dis.second][dis.first]=9;
		return visited[dis.second][dis.first]-1;
	}
	return 0;
}

void initvisit(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			visited[i][j]=0;
		}
	}
}

int main(void){
	cin>>N;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>map[i][j];
		}
	}
	int totaltime=0;
	while(1){
		initvisit();
		int sol=bfs();
		totaltime+=sol;
		if(sol==0){
			break;
		}
	}
	cout<<totaltime<<endl;
}
