#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[4][4];
int visited[4][4];
int fishdir[17];
int dx[9]={0,0,-1,-1,-1,0,1,1,1};
int dy[9]={0,-1,-1,0,1,1,1,0,-1};
int sol=0;

int isval(int x,int y){
	return x>=0&&x<4&&y>=0&&y<4;
}

void backt(int x,int y,int d,int k){
	if(visited[y][x]){
		sol=max(sol,k);
		return ;
	}
	
	d=fishdir[map[y][x]];
	visited[y][x]=1;
	int tx=x;
	int ty=y;
	while(isval(tx,ty)){
		tx+=dx[d];
		ty+=dy[d];
		map
}



int main(void){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cin>>map[i][j];
			cin>>fishdir[map[i][j]];
		}
	}

	backt(0,0,0,1);
}
