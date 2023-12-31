#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

char map[1000][1000];
int visited[1000][1000][2];
int N,M;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int bfs(){
	queue<tuple<int,int,int> >q;
	tuple<int,int,int>start=make_tuple(0,0,0);
	q.push(start);
	visited[get<1>(start)][get<0>(start)][get<2>(start)]=1;
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
		
		if(get<2>(current)<1){
			for(int i=0;i<4;i++){
				int nx=dx[i]+get<0>(current);
				int ny=dy[i]+get<1>(current);
			
				if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[ny][nx]=='1'&&!visited[ny][nx][get<2>(current)+1]){
					q.push(make_tuple(nx,ny,get<2>(current)+1));
					visited[ny][nx][get<2>(current)+1]=visited[get<1>(current)][get<0>(current)][get<2>(current)]+1;
				}
			}
		}
		cout<<"x: "<<get<0>(current)<<"y: "<<get<1>(current)<<"cost"<<visited[get<1>(current)][get<0>(current)][get<2>(current)]-1<<endl; 
	}
	return 0;
}

int main(void){
	cin>>N>>M;

	for(int i=0;i<N;i++){
		cin>>map[i];
	}

	int sol=bfs();
	
	
	if(sol==0){
		cout<<"-1"<<endl;
	}
	else{
		cout<<sol<<endl;
	}
}
