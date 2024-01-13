#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int nummap[1500][1500];
char map1[1500][1500];
int visited[1500][1500];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int R,C;
queue<pair<pair<int,int>,int> >q;
int bnum[2];
int qtoggle=0;
queue<pair<pair<int,int>,int> >q2;
set<set<int> >sv;

int isval(int x,int y){
	return x>=0&&x<C&&y>=0&&y<R;
}

int chk(int x,int y){
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(isval(nx,ny)&&(nummap[ny][nx]==bnum[0]&&nummap[y][x]==bnum[1])||((nummap[ny][nx]==bnum[1])&&nummap[ny][nx]==bnum[0])){
			return 1;
		}
	}
	return 0;
}

void bfs(int x,int y,int num){

	vector<pair<int,int> >v;
	q.push(make_pair(make_pair(x,y),num));
	visited[y][x]=1;
	nummap[y][x]=num;

	while(!q.empty()){
		pair<pair<int,int>,int>current=q.front();
		q.pop();
		
		pair<int,int>coor=current.first;
		int cx=coor.first;
		int cy=coor.second;
		
		for(int i=0;i<4;i++){
			int nx=cx+dx[i];
			int ny=cy+dy[i];
			
			if(isval(nx,ny)&&!visited[ny][nx]){
				if(map1[ny][nx]=='X'){
					v.push_back(make_pair(nx,ny));
					visited[ny][nx]=1;
				}
				else if(map1[ny][nx]!='X'){
					visited[ny][nx]=1;
					nummap[ny][nx]=current.second;
					q.push(make_pair(make_pair(nx,ny),current.second));
				}
			}
		}
	}
	for(int i=0;i<v.size();i++){
		map1[v[i].second][v[i].first]='.';
		nummap[v[i].second][v[i].first]=num;
		q2.push(make_pair(make_pair(v[i].first,v[i].second),num));
	}
}

int main(void){
	cin>>R>>C;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>map1[i][j];
		}
	}
	int num=1;
	int bb=0;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(map1[i][j]!='X'&&!visited[i][j]){
				bfs(j,i,num);
				set<int>tmp={num};
				sv.insert(tmp);
				num++;
			}

			if(bb<2&&map1[i][j]=='L'&&nummap[i][j]!=0){
				bnum[bb]=nummap[i][j];
				bb++;
			}
		}
	}
	
	int time=1;
	while(!q2.empty()){
		int Qsize=q2.size();
		time++;	
		for(int i=0;i<Qsize;i++){
			pair<pair<int,int>,int>current=q2.front();
			q2.pop();

			pair<int,int>coor=current.first;
			int tx=coor.first;
			int ty=coor.second;
	
			for(int i=0;i<4;i++){
				int nx=tx+dx[i];
				int ny=ty+dy[i];
					
				if(isval(nx,ny)&&((nummap[ny][nx]==bnum[0]&&nummap[ty][tx]==bnum[1])||nummap[ny][nx]==bnum[1]&&nummap[ty][tx]==bnum[0])){
					cout<<time<<endl;
					return 0;
				}

				if(chk(nx,ny)){
					cout<<time<<endl;
					return 0;
				}

				if(

				if(isval(nx,ny)&&!visited[ny][nx]&&map1[ny][nx]=='X'){
					q2.push(make_pair(make_pair(nx,ny),current.second));
					nummap[ny][nx]=current.second;
					visited[ny][nx]=1;
				}
			}
		}
	}
}
