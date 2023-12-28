#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int S[10];
char map[1000][1000];
char map2[1000][1000];
int visited[1000][1000];
int N,M,P;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int terinum[10];

int isval(int x,int y){
	return x>=0&&x<M&&y>=0&&y<N&&map[y][x]=='.'&&!visited[y][x];
}

int bfs(){
	queue<tuple<int,int,int> >q;
	int but=0;
	for(int k=1;k<=P;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				if(map[i][j]=='0'+k){
					q.push(make_tuple(j,i,k));
					visited[i][j]=1;
				}
			}
		}
		while(!q.empty()){
			tuple<int,int,int>current=q.front();
			q.pop();
			
			for(int i=0;i<4;i++){
				int nx=dx[i]+get<0>(current);
				int ny=dy[i]+get<1>(current);
				
				if(isval(nx,ny)&&visited[get<1>(current)][get<0>(current)]<=S[get<2>(current)]){
					visited[ny][nx]=visited[get<1>(current)][get<0>(current)]+1;
					map[ny][nx]='0'+k;
					q.push(make_tuple(nx,ny,get<2>(current)));
					but=1;
				}
			}
		}
	}
	return but;
}

int main(void){
	cin>>N>>M>>P;
	for(int i=1;i<=P;i++){
		cin>>S[i];
	}
	
	for(int i=0;i<N;i++){
		cin>>map[i];
	}
	int sol=1;
	while(sol){
		sol=bfs();
	}


	for(int i=0;i<N;i++){
		cout<<map[i]<<endl;
	}	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			terinum[map[i][j]-'0']++;
		}
	}
	for(int i=1;i<=P;i++){
		cout<<terinum[i]<<" ";
	}
	cout<<endl;
}
