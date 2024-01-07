#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[50][50];
int map[50][50];
int tmpmap[50][50];
int N,M;
int G,R;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int sol=0;
vector<pair<int,int> >Gr;
vector<pair<int,int> >Re;

int isval(int x,int y){
	return x>=0&&x<M&&y>=0&&y<N;
}

int isflower(int x,int y){
	int toggle=0;
	for(int i=0;i<4;i++){
		int nx=dx[i]+x;
		int ny=dy[i]+y;
		if(isval(nx,ny)&&tmpmap[ny][nx]==3&&visited[ny][nx]==visited[y][x]-1){
			tmpmap[ny][nx]=5;
			toggle=1;
		}
	}
	if(toggle){
		return 1;
	}
	return 0;
}

int bfs(){
	queue<pair<int,int> >G;
	queue<pair<int,int> >R;
	int fl=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			visited[i][j]=0;
			if(map[i][j]==4){
				G.push(make_pair(j,i));
				visited[i][j]=1;
			}
			else if(map[i][j]==3){
				R.push(make_pair(j,i));
				visited[i][j]=1;
			}
			tmpmap[i][j]=map[i][j];
		}
	}
	while(!G.empty()||!R.empty()){
		int Gsize=G.size();
		for(int i=0;i<Gsize;i++){
			pair<int,int>current=G.front();
			G.pop();
			if(tmpmap[current.second][current.first]==5){
				continue ;
			}
			for(int j=0;j<4;j++){
				int nx=dx[j]+current.first;
				int ny=dy[j]+current.second;
				
				if(isval(nx,ny)&&(tmpmap[ny][nx]==1||tmpmap[ny][nx]==2)&&!visited[ny][nx]){
					tmpmap[ny][nx]=4;
					G.push(make_pair(nx,ny));
					visited[ny][nx]=visited[current.second][current.first]+1;
				}
			}
		}
		int Rsize=R.size();
		for(int i=0;i<Rsize;i++){
			pair<int,int>current=R.front();
			R.pop();
			for(int j=0;j<4;j++){
				int nx=dx[j]+current.first;
				int ny=dy[j]+current.second;
				
				if(isval(nx,ny)&&(tmpmap[ny][nx]==1||tmpmap[ny][nx]==2)&&!visited[ny][nx]){
					tmpmap[ny][nx]=3;
					R.push(make_pair(nx,ny));
					visited[ny][nx]=visited[current.second][current.first]+1;
				}
				else if(isval(nx,ny)&&tmpmap[ny][nx]==4&&visited[ny][nx]-1==visited[current.second][current.first]){
					tmpmap[ny][nx]=5;
				}
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(tmpmap[i][j]==5){
				fl++;
			}
		}
	}
	return fl;			
}

void Green(int k,int idx){
	if(k==G){
		int flo=bfs();
		sol=max(sol,flo);
		return ;
	}

	for(int i=idx;i<Gr.size();i++){
		if(map[Gr[i].second][Gr[i].first]==2){
			map[Gr[i].second][Gr[i].first]=4;
			Green(k+1,i+1);
			map[Gr[i].second][Gr[i].first]=2;
		}
	}
}

void Red(int k,int idx){
	if(k==R){
		Green(0,0);
		return ;
	}

	for(int i=idx;i<Re.size();i++){
		if(map[Re[i].second][Re[i].first]==2){
			map[Re[i].second][Re[i].first]=3;
			Red(k+1,i+1);
			map[Re[i].second][Re[i].first]=2;
		}
	}
}

int main(void){
	cin>>N>>M>>G>>R;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
			if(map[i][j]==2){
				Gr.push_back(make_pair(j,i));
				Re.push_back(make_pair(j,i));
			}
		}
	}
	Red(0,0);
	cout<<sol<<endl;
}
	
	
