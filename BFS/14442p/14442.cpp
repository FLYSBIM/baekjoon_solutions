#include <iostream>
#include <tuple>
#include <queue>
#include <vector>

using namespace std;

char map[1000][1000];
int visited[1000][1000][11];
int N,M,K;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int bfs(){
	queue<tuple<int,int,int> >q;
	q.push(make_tuple(0,0,0));
	visited[0][0][0]=1;
	
	while(!q.empty()){
		tuple<int,int,int>current=q.front();
		q.pop();
		if(get<0>(current)==M-1&&get<1>(current)==N-1){
			return visited[get<1>(current)][get<0>(current)][get<2>(current)];
		}
		for(int i=0;i<4;i++){
			int nx=dx[i]+get<0>(current);
			int ny=dy[i]+get<1>(current);
		
			if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[ny][nx]=='0'&&!visited[ny][nx][get<2>(current)]){
				q.push(make_tuple(nx,ny,get<2>(current)));
				visited[ny][nx][get<2>(current)]=visited[get<1>(current)][get<0>(current)][get<2>(current)]+1;
			}
		}
		
		if(get<2>(current)<K){
			for(int i=0;i<4;i++){
				int nx=dx[i]+get<0>(current);
				int ny=dy[i]+get<1>(current);
			
				if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[ny][nx]=='1'&&!visited[ny][nx][get<2>(current)+1]){
					q.push(make_tuple(nx,ny,get<2>(current)+1));
					visited[ny][nx][get<2>(current)+1]=visited[get<1>(current)][get<0>(current)][get<2>(current)]+1;
				}
			}
		}
	}
	return 0;
}

int main(void){
	cin>>N>>M>>K;

	for(int i=0;i<N;i++){
		cin>>map[i];
	}
	
	int sol=bfs();

	if(sol==0){
		cout<<-1<<endl;
	}
	else{
		cout<<sol<<endl;
	}
}
