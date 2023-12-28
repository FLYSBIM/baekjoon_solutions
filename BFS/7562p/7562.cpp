#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[300][300];
int dx[8]={1,1,2,2,-1,-1,-2,-2};
int dy[8]={2,-2,1,-1,2,-2,1,-1};
int l;
int X1,Y1,X2,Y2;
int bfs(){
	queue<pair<int,int> >q;
	q.push(make_pair(X1,Y1));
	visited[Y1][X1]=1;
	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();
		if(current.first==X2&&current.second==Y2){
			return visited[current.second][current.first]-1;
		}
		
		for(int i=0;i<8;i++){
			int nx=dx[i]+current.first;
			int ny=dy[i]+current.second;
			
			if(nx>=0&&nx<l&&ny>=0&&ny<l&&!visited[ny][nx]){
				q.push(make_pair(nx,ny));
				visited[ny][nx]=visited[current.second][current.first]+1;
			}
		}
	}
	return 0;
}

int main(void){
	int T=0;
	cin>>T;
	while(T--){
		cin>>l;
		cin>>X1>>Y1;
		cin>>X2>>Y2;
		for(int i=0;i<l;i++){
			for(int j=0;j<l;j++){
				visited[i][j]=0;
			}
		}
		int sol=bfs();
		cout<<sol<<endl;
	}
}
