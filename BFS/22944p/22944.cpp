#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char map[500][500];
int visited[500][500][10];
int N,H,D;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int sol=100000000;
int toggle=0;
/*
void initvisit(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			visited[i][j]=0;
		}
	}
}*/

void backt(int x,int y,int hp,int Dp,int k,int Um){
	if(hp==0){
		return ;
	}

	if(map[y][x]=='E'){
		sol=min(sol,k);
		toggle=1;
		return ;
	}

	visited[y][x][Um]=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(nx>=0&&nx<N&&ny>=0&&ny<N&&hp>=1&&!visited[ny][nx][Um]){
			if(map[ny][nx]=='.'){
				if(Dp>=1){
					backt(nx,ny,hp,Dp-1,k+1,Um);
				}
				else if(Dp==0){
					backt(nx,ny,hp-1,Dp,k+1,Um);
				}
			}
			else if(map[ny][nx]=='U'){
			//	initvisit();
				backt(nx,ny,hp,D,k+1,Um+1);
			}
			else if(map[ny][nx]=='E'){
				backt(nx,ny,hp,D,k+1,Um);
			}
			else if(map[ny][nx]=='S'){
				backt(nx,ny,hp,D,k+1,Um);
			}
		}
	}
	visited[y][x][Um]=0;
}
int main(void){
	cin>>N>>H>>D;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>map[i][j];
		}
	}
	cout<<"comple"<<endl;
	backt(0,0,H,0,0,0);
	
	if(sol==100000000){
		cout<<-1<<endl;
	}
	else{
 		cout<<sol<<endl;
	}
}	
