#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

char map[50][50];
int visited[50][50];
int N,M;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
queue<tuple<int,int,int,int,int> >q;
//x,y,dir,pre,time
int cnt=0;

int isval(int x,int y){
	return x>=0&&x<M&&y>=0&&y<N;
}

int bfs(){
	tuple<int,int,int,int,int>current=q.front();
	q.pop();
	for(int i=0;i<4;i++){
		int nx=get<0>(current)+dx[i];
		int ny=get<1>(current)+dy[i];

		if(isval(nx,ny)&&map[ny][nx]!='#'){
			if(map[ny][nx]=='C'){
				map[ny][nx]='.';
				q.push(make_tuple(nx,ny,i,get<3>(current)+1,get<4>(current)+1));
			}
			else if(map[ny][nx]=='S'||map[ny][nx]=='.'){
				q.push(make_tuple(nx,ny,i,get<3>(current),get<4>(current)+1));
			}
		}
	}
			
	while(!q.empty()){
		tuple<int,int,int,int,int>current=q.front();
		q.pop();
		if(get<3>(current)==cnt){
			return get<4>(current);
		}
		for(int i=0;i<4;i++){
			if(i!=get<2>(current)){		
				int nx=get<0>(current)+dx[i];
				int ny=get<1>(current)+dy[i];
				if(isval(nx,ny)&&map[ny][nx]!='#'){
					if(map[ny][nx]=='C'){
						map[ny][nx]='.';
						q.push(make_tuple(nx,ny,i,get<3>(current)+1,get<4>(current)+1));
					}
					else if(map[ny][nx]=='S'||map[ny][nx]=='.'){
						q.push(make_tuple(nx,ny,i,get<3>(current),get<4>(current)+1));
					}
				}
			}
		}
	}
	return -1;
}

int main(void){
	cin>>N>>M;
	
	for(int i=0;i<N;i++){
		cin>>map[i];
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]=='S'){
				q.push(make_tuple(j,i,-1,0,0));
			}
			else if(map[i][j]=='C'){
				cnt++;
			}
		}
	}
	int sol=bfs();
	cout<<sol<<endl;
}
