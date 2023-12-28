#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int map[100][100];
int visited[100][100];
int N;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};


int isval(int x,int y){
	return x>=0&&x<N&&y>=0&&y<N;
}

int isedge(int x,int y){
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(isval(nx,ny)&&map[ny][nx]==0){
			return 1;
		}
	}
	return 0;
}

int bfs(int x,int y){
	queue<tuple<int,int,int> >q;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			q.push(make_tuple(j,i,
	
	
}

int main(void){
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>map[i][j];
		}
	}
	
	
	
}
