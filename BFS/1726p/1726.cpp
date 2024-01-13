#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[100][100];
int visited[100][100][4];
int M,N;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
queue<pair<pair<int,int>,int> >q;
int endx,endy,endd;
int tmpx,tmpy,tmpd;

int isval(int x,int y){
	return x>=0&&x<N&&y>=0&&y<M;
}

int gostraight(int x,int y,int d){
	int tx=x;
	int ty=y;
	while(1){
		int nx=tx+dx[d];
		int ny=ty+dy[d];
		if(isval(nx,ny)&&map[ny][nx]!=1){
			tx+=dx[d];
			ty+=dy[d];
		}
		else if(!isval(nx,ny)||map[ny][nx]==1){
			break;
		}
	}
	tmpx=tx;
	tmpy=ty;
	tmpd=d;
	if(visited[ty][tx][d]){
		return 0;
	}
	return 1;
}	

int bfs(){
	int time=0;
	int toggle=0;
	while(!q.empty()){
		int Qsize=q.size();
		cout<<Qsize<<endl;
		for(int i=0;i<Qsize;i++){
			pair<pair<int,int>,int>current=q.front();
			q.pop();
			pair<int,int>coor=current.first;
			int cx=coor.first;
			int cy=coor.second;
			int cd=current.second;

			if(cx==endx&&cy==endy&&cd==endd){
				toggle=1;
				break;
			}	

			if(gostraight(cx,cy,cd)){
				visited[tmpy][tmpx][tmpd]=1;
				q.push(make_pair(make_pair(cx,cy),cd));
			}
			
			if(cd+1==4&&!visited[cy][cx][0]){
				visited[cy][cx][0]=1;
				q.push(make_pair(make_pair(cx,cy),0));
			}
			else if(cd+1<4&&!visited[cy][cx][cd+1]){
				visited[cy][cx][cd+1]=1;
				q.push(make_pair(make_pair(cx,cy),cd+1));
			}

			if(cd-1==-1&&!visited[cy][cx][3]){
				visited[cy][cx][3]=1;
				q.push(make_pair(make_pair(cx,cy),3));
			}
			else if(cd-1>-1&&!visited[cy][cx][cd-1]){
				visited[cy][cx][cd-1]=1;
				q.push(make_pair(make_pair(cx,cy),cd-1));
			}
		}
		if(toggle){
			break;
		}
		time++;
	}
	return time;
}

int main(void){
	cin>>M>>N;

	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin>>map[i][j];
		}
	}

	int sx,sy,sd;
	cin>>sx>>sy>>sd;
	q.push(make_pair(make_pair(sx-1,sy-1),sd));
	visited[sy-1][sx-1][sd]=1;

	cin>>endy>>endx>>endd;
	endy--;
	endx--;
	int sol=bfs();
	cout<<sol<<endl;
}
