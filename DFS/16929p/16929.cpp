#include <iostream>
#include <vector>

using namespace std;

char map[50][50];
int visited[50][50];
int N,M;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int toggle=0;
int area=1;

int isval(int x,int y){
	return x>=0&&x<M&&y>=0&&y<N;
}

int isfron(int x,int y,char alp){
	for(int i=0;i<4;i++){
		int nx=dx[i]+x;
		int ny=dy[i]+y;
		
		if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[ny][nx]==alp){
			return 1;
		}
	}
	return 0;
}	

int dfs(int x,int y,char alp){
	visited[y][x]=area;
	cout<<"x:y"<<x<<" "<<y<<endl;	
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
	
		if(isval(nx,ny)&&!visited[ny][nx]&&map[ny][nx]==alp){
			area++;
			dfs(nx,ny,alp);
		}
	}
	return 0;
}

int main(void){
	cin>>N>>M;
	
	for(int i=0;i<N;i++){
		cin>>map[i];
	}


	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(!visited[i][j]){
				dfs(j,i,map[i][j]);
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<visited[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"No"<<endl;
}
