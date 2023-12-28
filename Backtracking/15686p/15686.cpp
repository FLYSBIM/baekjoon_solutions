#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int tempmap[50][50];
int map[50][50];
int visited[50][50];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int N,M;
int sol=2000000000;
int cntck;
void bfs(){
	queue<pair<int,int> >c;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			visited[i][j]=0;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(map[i][j]==2){
				c.push(make_pair(j,i));
				visited[i][j]=1;
			}
			tempmap[i][j]=map[i][j];
		}
	}
	
	while(!c.empty()){
		pair<int,int>current=c.front();
		c.pop();
		
		for(int i=0;i<4;i++){
			int nx=dx[i]+current.first;
			int ny=dy[i]+current.second;
		
			if(nx>=0&&nx<N&&ny>=0&&ny<N&&!visited[ny][nx]&&tempmap[ny][nx]!=2){
				c.push(make_pair(nx,ny));
				tempmap[ny][nx]=2;
				visited[ny][nx]=visited[current.second][current.first]+1;
			}
		}
	}
}

int cdistance(){
	int dis_sum=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(map[i][j]==1){
				dis_sum=dis_sum+visited[i][j]-1;
			}
		}
	}
	return dis_sum;
}	

void downchick(int k,int startrow){
	if(k==cntck-M){
		bfs();
		int dis=cdistance();
		sol=min(sol,dis);
		return ;
	}

	for(int i=startrow;i<N;i++){
		for(int j=0;j<N;j++){
			if(map[i][j]==2){
				map[i][j]=0;
				downchick(k+1,i);
				map[i][j]=2;
			}
		}
	}
}
		
int main(void){
	cin>>N>>M;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>map[i][j];
			if(map[i][j]==2){
				cntck++;
			}
		}
	}
	downchick(0,0);
	cout<<sol<<endl;
}
