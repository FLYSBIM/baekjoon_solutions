#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[200][200]={0};
int dx[6]={-2,-2,0,0,2,2};
int dy[6]={-1,1,-2,2,-1,1};
int N;
int r1,c1,r2,c2;

int bfs(){
	queue<pair<int,int> >q;
	pair<int,int>end=make_pair(r2,c2);
	q.push(make_pair(r1,c1));
	visited[c1][r1]=1;
	int time=0;
	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();
		if(current.first==end.first&&current.second==end.second){
			return visited[current.second][current.first]-1;
		}

		for(int i=0;i<6;i++){
			int nx=dx[i]+current.first;
			int ny=dy[i]+current.second;
		
			if(nx>=0&&nx<N&&ny>=0&&ny<N&&!visited[ny][nx]){
				visited[ny][nx]=visited[current.second][current.first]+1;
				q.push(make_pair(nx,ny));
			}
		}
	}
	return -1;
}

int main(void){
	cin>>N;
	cin>>r1>>c1>>r2>>c2;

	int sol=bfs();
	if(sol==-1){
		cout<<-1<<endl;
	}
	else{
		cout<<sol<<endl;
	}
}
