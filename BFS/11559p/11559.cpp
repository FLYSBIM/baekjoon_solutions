#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[12][6];
int visited[12][6];
int garea=0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int isval(int x,int y){
	return x>=0&&x<6&&y>=0&&y<12;
}

void initvisit(){
	for(int i=0;i<12;i++){
		for(int j=0;j<6;j++){
			visited[i][j]=0;
		}
	}
}

vector<pair<int,int> > bfs(int x,int y){
	queue<pair<int,int> >q;
	q.push(make_pair(x,y));
	visited[y][x]=1;
	vector<pair<int,int> >v;
	v.push_back(make_pair(x,y));
	int area=1;

	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int nx=current.first+dx[i];
			int ny=current.second+dy[i];

			if(isval(nx,ny)&&map[ny][nx]==map[y][x]&&!visited[ny][nx]){
				area++;
				q.push(make_pair(nx,ny));
				visited[ny][nx]=1;
				v.push_back(make_pair(nx,ny));
			}
		}
	}
	garea=area;
	return v;
}

void puyo(vector<pair<int,int> >co){
	for(int i=0;i<co.size();i++){
		map[co[i].second][co[i].first]='.';
	}
}

void down(){
	for(int i=10;i>=0;i--){
		for(int j=0;j<6;j++){
			if(map[i][j]!='.'){
				int ty=i;
				while(1){
					int ny=ty+1;
					if(ny>=12||map[ny][j]!='.'){
						break;
					}
					map[ny][j]=map[ty][j];
					map[ty][j]='.';
					ty++;
				}
			}
		}
	}
}
	

int main(void){
	for(int i=0;i<12;i++){
		for(int j=0;j<6;j++){
			cin>>map[i][j];
		}
	}
	int squ=0;
	while(1){
		int toggle=1;
		initvisit();
		for(int i=0;i<12;i++){
			for(int j=0;j<6;j++){
				if(map[i][j]!='.'&&!visited[i][j]){
					vector<pair<int,int> >coor=bfs(j,i);
					if(garea>=4){
						puyo(coor);
						toggle=0;
					}
				}
			}
		}
		down();
		if(toggle){
			break;
		}
		squ++;	
	}
	cout<<squ<<endl;
}
