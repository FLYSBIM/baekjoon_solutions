#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[1000][1000];
int map[1000][1000];
int N,M;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<pair<int,int> >v;
vector<pair<int,int> >v2;
int asize[500000];
int toggle[500000];

int isval(int x,int y){
	return x>=0&&x<M&&y>=0&&y<N;
}

int isadj(int x,int y){
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(isval(nx,ny)&&map[y][x]==0&&map[ny][nx]!=0){
			return 1;
		}
	}
	return 0;
}

int numbering(int x,int y,int areanum){
	visited[y][x]=1;
	map[y][x]=areanum;
	int area=1;

	for(int i=0;i<4;i++){
		int nx=dx[i]+x;
		int ny=dy[i]+y;

		if(isval(nx,ny)&&!visited[ny][nx]&&map[ny][nx]==1){
			area+=numbering(nx,ny,areanum);
		}
	}
	return area;
}

int objsize(int x,int y){
	int objsize=1;
	for(int i=0;i<4;i++){
		int nx=dx[i]+x;
		int ny=dy[i]+y;

		if(isval(nx,ny)&&toggle[map[ny][nx]]==0){
			objsize+=asize[map[ny][nx]];
			toggle[map[ny][nx]]=1;
			v2.push_back(make_pair(nx,ny));
		}
	}
	while(!v2.empty()){
		pair<int,int>current=v2.back();
		toggle[map[current.second][current.first]]=0;
		v2.pop_back();
	}
	return objsize;
}

int main(void){
	cin>>N>>M;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
		}
	}

	int arean=1;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]==0&&isadj(j,i)){
				v.push_back(make_pair(j,i));
			}
			
			if(!visited[i][j]&&map[i][j]!=0){
				asize[arean]=numbering(j,i,arean);
				arean++;
			}
		}
	}

	int sol=0;
	for(int i=0;i<v.size();i++){	
		int a=objsize(v[i].first,v[i].second);
		sol=max(sol,a);
	}
		
	cout<<sol<<endl;
}
