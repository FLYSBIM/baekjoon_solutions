#include <iostream>
#include <vector>

using namespace std;

char map[20][20];
int visited[20][20];
int alp[26];
int R,C;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int area=1;
int marea=1;
int dfs(int x,int y){

	alp[map[y][x]-'A']=1;
	visited[y][x]=1;
	for(int i=0;i<4;i++){
		int nx=dx[i]+x;
		int ny=dy[i]+y;

		if(nx>=0&&nx<C&&ny>=0&&ny<R&&!alp[map[ny][nx]-'A']&&!visited[ny][nx]){
			alp[map[ny][nx]-'A']=1;
			visited[ny][nx]=1;
			area++;
			marea=max(area,marea);
			dfs(nx,ny);
			alp[map[ny][nx]-'A']=0;
			visited[ny][nx]=0;
			area--;
		}
	}
	return 1;
}

int main(void){
	cin>>R>>C;

	for(int i=0;i<R;i++){
		cin>>map[i];
	}
	
	dfs(0,0);
	cout<<marea<<endl;
}
