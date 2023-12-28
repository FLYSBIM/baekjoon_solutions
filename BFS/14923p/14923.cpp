#include <iostream>
#include <tuple>
#include <queue>
#include <vector>

using namespace std;

int map[1000][1000]={0};
int visited[1000][1000][2]={0};
int N,M,Hx,Hy,Ex,Ey;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int bfs(){
	queue<tuple<int,int,int> >q;
	q.push(make_tuple(Hy-1,Hx-1,0));
	visited[Hx-1][Hy-1][0]=1;
	
	while(!q.empty()){
		tuple<int,int,int>current=q.front();
		q.pop();

		if(get<0>(current)==Ey-1&&get<1>(current)==Ex-1){
			return visited[get<1>(current)][get<0>(current)][get<2>(current)]-1;
		}

		for(int i=0;i<4;i++){
			int nx=dx[i]+get<0>(current);
			int ny=dy[i]+get<1>(current);
			
			if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[ny][nx]==0&&!visited[ny][nx][get<2>(current)]){
				q.push(make_tuple(nx,ny,get<2>(current)));
				visited[ny][nx][get<2>(current)]=visited[get<1>(current)][get<0>(current)][get<2>(current)]+1;
			}
		}

		if(get<2>(current)<1){	
			for(int i=0;i<4;i++){
				int nx=dx[i]+get<0>(current);
				int ny=dy[i]+get<1>(current);
			
				if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[ny][nx]==1&&!visited[ny][nx][get<2>(current)+1]){
					q.push(make_tuple(nx,ny,1));
					visited[ny][nx][get<2>(current)+1]=visited[get<1>(current)][get<0>(current)][get<2>(current)]+1;
				}
			}
		}
	}
	return -1;
}


int main(void){
	cin>>N>>M;
	cin>>Hx>>Hy;
	cin>>Ex>>Ey;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
		}
	}

	int sol=bfs();

	if(sol==-1){
		cout<<-1<<endl;
	}
	else{
		cout<<sol<<endl;
	}
}
