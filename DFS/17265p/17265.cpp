#include <iostream>

char map[5][5];
int visited[5][5];
int N;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int dfs(int x,int y){
	visited[y][x]=1;
	
	
	for(int i=0;i<4;i++){
		int nx=dx[i]+x;
		int ny=dy[i]+y;
			
		if(nx>=0&&nx<N&&ny>=0&&ny<N){
			if(map[y][x]=='+'){
				
	
}

int main(void){
	cin>>N;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>map[i][j];
		}
	}
	
		
