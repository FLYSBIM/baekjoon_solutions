#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[1000][1000];
int visited[1000][1000];
int N,M;
int K;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
priority_queue<pair<int,pair<int,int> > >pq;
vector<pair<int,int> >corn;

int bfs(){
	while(K--){
		pair<int,pair<int,int> >current=pq.top();
		pq.pop();
		int x=current.second.first;
		int y=current.second.second;
		corn.push_back(make_pair(x,y));
		for(int i=0;i<4;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx>=0&&nx<M&&ny>=0&&ny<N&&!visited[ny][nx]){
				pq.push(make_pair(map[ny][nx],make_pair(nx,ny)));
				visited[ny][nx]=1;
			}
		}
	}
	return 1;
}

int main(void){
	cin>>N>>M;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
			if(i==0||j==0||i==N-1||j==M-1){
				pq.push(make_pair(map[i][j],make_pair(j,i)));
				visited[i][j]=1;
			}
		}
	}
	cin>>K;
	bfs();
	for(int i=0;i<corn.size();i++){
		cout<<corn[i].second+1<<" "<<corn[i].first+1<<endl;
	}
}
