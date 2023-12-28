#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[101][101];
int visited[101][101];
int N,M;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<vector<vector<pair<int,int> > > >s;

void bright(int x,int y){
        for(int i=0;i<s[y][x].size();i++){
                map[s[y][x][i].second][s[y][x][i].first]=1;
        }
}

int bfs(){
	queue<pair<int,int> >q;
	q.push(make_pair(1,1));
	visited[1][1]=1;
	map[1][1]=1;
	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();
		//bright(current.first,current.second);
		
		for(int i=0;i<4;i++){
			int nx=dx[i]+current.first;
			int ny=dy[i]+current.second;
			
			if(nx>0&&nx<=N&&ny>0&&ny<=N&&map[ny][nx]==1&&!visited[ny][nx]){
				q.push(make_pair(nx,ny));
				visited[ny][nx]=1;
			}
		}
	}
	return 1;
}

int main(void){
	cin>>N>>M;
	s.resize(6, vector<vector<pair<int, int> > >(6));
	int x,y,a,b;
	for(int i=0;i<M;i++){
		cin>>x>>y>>a>>b;
		s[y][x].push_back(make_pair(a,b));
		map[b][a]=1;
	}
	bfs();
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout<<visited[i][j]<<" ";
		}
		cout<<endl;
	}	
}
