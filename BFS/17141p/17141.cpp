#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int tmpmap[50][50];
int map[50][50];
int visited[50][50];
int N,M;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<pair<int,int> >vi;
int vircnt=0;
int sol=100000;

int bfs(){
	queue<pair<int,int> >q;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			tmpmap[i][j]=map[i][j];
			visited[i][j]=0;
			if(map[i][j]==2){
				q.push(make_pair(j,i));
				visited[i][j]=1;
			}
		}
	}
	int t=0;
	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();
		t=max(t,visited[current.second][current.first]-1);
		for(int i=0;i<4;i++){
			int nx=dx[i]+current.first;
			int ny=dy[i]+current.second;
			
			if(nx>=0&&nx<N&&ny>=0&&ny<N&&tmpmap[ny][nx]==0&&!visited[ny][nx]){
				q.push(make_pair(nx,ny));
				visited[ny][nx]=visited[current.second][current.first]+1;
				tmpmap[ny][nx]=2;
			}
		}
	}

	int but=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(tmpmap[i][j]==0){
				but=1;
			}
		}
	}
	if(but){
		return -1;
	}

	return t;
}

void virus(int k,int idx){
	if(k==vircnt-M){
		int time=bfs();
		if(time!=-1){
			sol=min(sol,time);
		}
		return ;
	}

	for(int i=idx;i<vi.size();i++){
		map[vi[i].second][vi[i].first]=0;
		virus(k+1,i+1);	
		map[vi[i].second][vi[i].first]=2;
	}
}

int main(void){
	cin>>N>>M;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>map[i][j];
			if(map[i][j]==2){
				vi.push_back(make_pair(j,i));
				vircnt++;
			}
		}
	}
	
	virus(0,0);
	if(sol==100000){
		cout<<-1<<endl;
	}
	else{
		cout<<sol<<endl;
	}
}
