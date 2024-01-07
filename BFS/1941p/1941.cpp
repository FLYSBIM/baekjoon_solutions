#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char tmpmap[5][5];
char map[5][5];
int visited[5][5];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int sol=0;

void dfs(int x,int y,int S,int Y){
	
	if(Y==4){
		return ;
	}	

	if(S+Y==7){
		sol++;		
		return ;
	}

	visited[y][x]=1;
	for(int i=0;i<4;i++){
		int nx=dx[i]+x;
		int ny=dy[i]+y;
		
		if(nx>=0&&nx<5&&ny>=0&&ny<5&&!visited[ny][nx]){
			if(map[ny][nx]=='S'){
				dfs(nx,ny,S+1,Y);		
			}
			else if(map[ny][nx]=='Y'){
				dfs(nx,ny,S,Y+1);
			}
		}
	}
	visited[y][x]=0;
}

void init(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			visited[i][j]=0;
		}
	}
}

int main(void){
	for(int i=0;i<5;i++){
		cin>>map[i];
	}

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			tmpmap[i][j]=map[i][j];
		}
	}

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(map[i][j]=='S'){
				init();
				dfs(j,i,1,0);
				map[i][j]='Y';
			}
		}
	}
	cout<<sol<<endl;
}
	
