#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int tmpmap[100][100];
int map[100][100];
int edgemap[100][100];
int visited[100][100];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int diax[4]={1,1,-1,-1};
int diay[4]={1,-1,1,-1};
int fron[100][100];
int toggle[100][100];
queue<pair<int,int> >q;

int isval(int x,int y){
	return x>=0&&x<N&&y>=0&&y<N;
}

int bfs(){
	while(!q.empty()){
		int Qsize=q.size();
		for(int j=0;j<Qsize;j++){
			pair<int,int>current=q.front();
			q.pop();		
			for(int i=0;i<4;i++){
				int nx=dx[i]+current.first;
				int ny=dy[i]+current.second;
			
				if(isval(nx,ny)&&map[ny][nx]!=map[current.second][current.first]){
					if(!visited[ny][nx]&&map[ny][nx]==0){
						q.push(make_pair(nx,ny));
						visited[ny][nx]=visited[current.second][current.first]+1;
						map[ny][nx]=map[current.second][current.first];
					}
					else if(toggle[ny][nx]==0&&map[ny][nx]!=0){
						fron[ny][nx]=visited[ny][nx]+visited[current.second][current.first]-2;
						toggle[ny][nx]=1;
					}
				}
			}
        	}
	}
	int aa=10000;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(fron[i][j]!=0){
				aa=min(aa,fron[i][j]);
			}
		}
	}			
	return aa;	
}

void dfs(int x,int y,int k){
	visited[y][x]=1;
	map[y][x]=k;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(isval(nx,ny)&&!visited[ny][nx]&&map[ny][nx]!=0){
			dfs(nx,ny,k);
		}
	}
}

void isedge(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<4;k++){
				int nx=j+dx[k];
				int ny=i+dy[k];
				
				if(map[i][j]==1&&nx>=0&&nx<N&&ny>=0&&ny<N&&map[ny][nx]==0){
					edgemap[i][j]=1;
					break;
				}
			}
		}
	}
}

int main(void){
	cin>>N;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>map[i][j];
			tmpmap[i][j]=map[i][j];
		}
	}
	
	isedge();

	int numb=1;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(map[i][j]!=0&&!visited[i][j]){
				dfs(j,i,numb);
				numb++;
			}
		}
	}

	for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
			visited[i][j]=0;
			if(edgemap[i][j]==1){
				q.push(make_pair(j,i));
				visited[i][j]=1;
			}
                }
        }
	int sol=bfs();
	cout<<sol<<endl;
}
	
