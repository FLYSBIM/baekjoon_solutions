#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[1000][1000];
int areanummap[1000][1000];
char visited[1000][1000];
int ans[1000][1000];
int N,M;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int areanum[500000];
int areabut[500000];

int bfs(int x,int y,int num){
	int area=0;
	queue<pair<int,int> >q;
	q.push(make_pair(x,y));
	visited[y][x]=1;
	areanummap[y][x]=num;
	area++;

	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx=dx[i]+current.first;
			int ny=dy[i]+current.second;
			
			if(nx>=0&&nx<M&&ny>=0&&ny<N&&!visited[ny][nx]&&map[ny][nx]=='0'){
				visited[ny][nx]=1;
				areanummap[ny][nx]=num;
				area++;
				q.push(make_pair(nx,ny));
			}
		}
	}
	return area;
}

int main(void){
	cin>>N>>M;

	for(int i=0;i<N;i++){
		cin>>map[i];
	}

	int arean=1;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]=='0'&&!visited[i][j]){
				areanum[arean]=bfs(j,i,arean);
				arean++;
			}
			ans[i][j]=map[i][j]-'0';
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(ans[i][j]==1){
				vector<int>aa;
				for(int k=0;k<4;k++){
					int nx=dx[k]+j;
					int ny=dy[k]+i;
					if(nx>=0&&nx<M&&ny>=0&&ny<N&&ans[ny][nx]==0&&areabut[areanummap[ny][nx]]==0){
						ans[i][j]+=areanum[areanummap[ny][nx]];
						areabut[areanummap[ny][nx]]=1;
						aa.push_back(areanummap[ny][nx]);
					}
				}
				ans[i][j]%=10;
				while(!aa.empty()){
					areabut[aa.back()]=0;
					aa.pop_back();
				}
			}
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<ans[i][j];
		}
		cout<<'\n';
	}
}
