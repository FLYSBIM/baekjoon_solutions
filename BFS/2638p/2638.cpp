#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[100][100];
int visited[100][100];
int N,M;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int dfs(int x,int y){
	if(map[y][x]==0){
		visited[y][x]=1;
	}
	else if(map[y][x]==1){
		visited[y][x]++;
		return 0;
	}

	for(int i=0;i<4;i++){
		int nx=dx[i]+x;
		int ny=dy[i]+y;
		if(nx>=0&&nx<M&&ny>=0&&ny<N){
			if(map[ny][nx]==0&&!visited[ny][nx]){
				dfs(nx,ny);
			}
			else if(map[ny][nx]==1&&visited[ny][nx]<2){
				dfs(nx,ny);
			}
		}
	}
	return 0;
}

void melt(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(visited[i][j]>=2){
				map[i][j]=0;
			}
			visited[i][j]=0;
		}
	}
}		

int isCheese(){
	int Cnum=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]==1){
				return 1;
			}
		}
	}
	return 0;
}

int main(void){
	cin>>N>>M;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
		}
	}
	
	int time=0;
	int sol=0;
	while(isCheese()){
		dfs(0,0);
		melt();
		time++;
	}
	cout<<time<<endl;
	cout<<sol<<endl;
}	
