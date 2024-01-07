#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int tmpmap[50][50];
int map[50][50];
int visited[50][50];
int N,M;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int viruscnt=0;
int t=100000;
vector<pair<int,int> >vir;
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
	int time=0;
	while(!q.empty()){
		int V_size=q.size();
	
		if(time>=t){
			break;
		}

		for(int j=0;j<V_size;j++){
			pair<int,int>current=q.front();
			q.pop();
			for(int i=0;i<4;i++){
				int nx=dx[i]+current.first;
				int ny=dy[i]+current.second;
			
				if(nx>=0&&nx<N&&ny>=0&&ny<N&&!visited[ny][nx]){
					if(map[ny][nx]==3){
						q.push(make_pair(nx,ny));
						visited[ny][nx]=visited[current.second][current.first]+1;
						tmpmap[ny][nx]=2;
					}
					else if(map[ny][nx]==0){	
						q.push(make_pair(nx,ny));
						visited[ny][nx]=visited[current.second][current.first]+1;
						tmpmap[ny][nx]=2;
						time=max(time,visited[ny][nx]-1);
					}
				}
			}
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(tmpmap[i][j]==0){
				return -1;
			}
		}
	}
	return time;
}

void virus(int k,int idx){
	if(k==viruscnt-M){
		int tsol=bfs();
		if(tsol!=-1){
			t=min(t,tsol);
		}
		return ;
	}
	for(int i=idx;i<vir.size();i++){
		map[vir[i].second][vir[i].first]=3;
		virus(k+1,i+1);
		map[vir[i].second][vir[i].first]=2;
	}
}

int main(void){
	cin>>N>>M;
	int but=1;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>map[i][j];
			if(map[i][j]==2){
				viruscnt++;
				vir.push_back(make_pair(j,i));
			}
			else if(map[i][j]==0){
				but=0;
			}
		}
	}
	if(but){
		cout<<0<<endl;
		return 0;
	}
	virus(0,0);
	if(t==100000){
		cout<<-1<<endl;
	}
	else{
		cout<<t<<endl;
	}
}
