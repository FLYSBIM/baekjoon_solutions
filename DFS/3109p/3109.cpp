#include <iostream>
#include <vector>

using namespace std;

char map[10000][500];
int visited[10000][500];
int dx[3]={1,1,1};
int dy[3]={-1,0,1};
int R,C;


int dfs(int x,int y){
	visited[y][x]=1;
	
	if(x==C-1){
		return 1;
	}


	for(int i=0;i<3;i++){
		int nx=dx[i]+x;
		int ny=dy[i]+y;
		
		if(nx>=0&&nx<C&&ny>=0&&ny<R&&map[ny][nx]=='.'&&!visited[ny][nx]){
			if(dfs(nx,ny)){
				return 1;
			}
		}
	}
	return 0;		
}

int main(void){
	cin>>R>>C;
	
	for(int i=0;i<R;i++){
		cin>>map[i];
	}

	int sol=0;
	for(int i=0;i<R;i++){
		int p=dfs(0,i);
		sol+=p;
	}
	cout<<sol<<endl;
}
