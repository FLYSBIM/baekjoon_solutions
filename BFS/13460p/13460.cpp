#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[10][10][10][10];
int pos=0;
int N,M;
char map[10][10];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
queue<pair<pair<int,int> ,pair<int,int> > >q;
int wx,wy;
int tmprx,tmpry,tmpbx,tmpby;
int isval(int x,int y){
	return x>=1&&x<M-1&&y>=1&&y<N-1;
}

int rolling(int r_x,int r_y,int b_x,int b_y,int d){
	int redx=r_x;
	int redy=r_y;
	int blx=b_x;
	int bly=b_y;

	int rout=0;
	int bout=0;
	while(1){
		int rnx=redx+dx[d];
		int rny=redy+dy[d];
		int rtoggle=1;
		int btoggle=1;		
		
		if(map[rny][rnx]=='O'){
			redx=-255;
			redy=-254;
			rout=1;
		}
		
		if(!rout&&map[rny][rnx]!='#'&&(rnx!=blx||rny!=bly)){
			redx+=dx[d];
			redy+=dy[d];
			rtoggle=0;
		}

		int bnx=blx+dx[d];
		int bny=bly+dy[d];
		if(map[bny][bnx]=='O'){
                        bout=1;
                        break;
                }

		if(map[bny][bnx]!='#'&&(redx!=bnx||redy!=bny)){
			blx+=dx[d];
			bly+=dy[d];
			btoggle=0;
		}

		if(rtoggle&&btoggle){
			break;
		}	
	}
	if(rout&&bout){
		return 0;
	}
	if(r_x==redx&&r_y==redy&&b_x==blx&&b_y==bly){
		return 3;
	}
	tmprx=redx;
	tmpry=redy;
	tmpbx=blx;
	tmpby=bly;
	if(!bout&&!rout){
		if(visited[redx][redy][blx][bly]){
			return 3;
		}
		else{
			visited[redx][redy][blx][bly]=1;
			return 1;
		}
	}
	if(bout){
		return 0;
	}
	
	if(!bout&&rout){
		return 2;
	}
	return 1;
}
/*
int bfs2(int x,int y){
	queue<pair<int,int> >q2;
	q2.push(make_pair(x,y));
	while(!q2.empty()){
		pair<int,int>current=q2.front();
		q2.pop();
		if(map[current.second][current.first]=='O'){
			pos=1;
		}
		for(int i=0;i<4;i++){
			int nx=dx[i]+current.first;
			int ny=dy[i]+current.second;
			if(nx>=0&&nx<M&&ny>=0&&ny<N&&!visited[ny][nx]&&map[ny][nx]!='#'){
				visited[ny][nx]=1;
				q2.push(make_pair(nx,ny));
			}
		}
	}
	return 1;
}*/

int bfs(){
	int time=0;
	int toggle=0;
	while(!q.empty()){
		int Qsize=q.size();
		for(int j=0;j<Qsize;j++){
			pair<pair<int,int>,pair<int,int> >current=q.front();
			q.pop();

			pair<int,int>red=current.first;
			pair<int,int>blue=current.second;
				
			for(int i=0;i<4;i++){
				int stance=rolling(red.first,red.second,blue.first,blue.second,i);
				if(stance==1){
					q.push(make_pair(make_pair(tmprx,tmpry),make_pair(tmpbx,tmpby)));
				}
				else if(stance==2){
					toggle=1;
					break;
				}
			}
			if(toggle){
				break;
			}
		}
		time++;
		if(toggle){
			break;
		}			
	}
	if(toggle==0){
		return -1;
	}
	return time;
}

int main(void){
	cin>>N>>M;
	int rx,ry,bx,by;	

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
			if(map[i][j]=='R'){
				map[i][j]='.';
				rx=j;
				ry=i;
			}
			else if(map[i][j]=='B'){
				map[i][j]='.';
				bx=j;
				by=i;
			}
			else if(map[i][j]=='O'){
				wx=j;
				wy=i;
			}	
		}
	}
	visited[rx][ry][bx][by]=1;
 	q.push(make_pair(make_pair(rx,ry),make_pair(bx,by)));
	int sol=bfs();
	cout<<sol<<endl;
}
