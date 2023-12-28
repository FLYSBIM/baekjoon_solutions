#include <iostream>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;

char map[1001][1001];
int N,M,K;
int dx[5]={1,-1,0,0,0};
int dy[5]={0,0,1,-1,0};
int visited[1001][1001][11];

int isval(int x,int y){
	return x>=0&&x<M&&y>=0&&y<N;
}

int bfs(){
	queue<tuple<int,int,int,int,int> >q;
	q.push(make_tuple(0,0,0,1,1));
	//x,y,break_wall,cost,time 1:morning -1:night
	visited[0][0][0]=1;	

	while(!q.empty()){
		tuple<int,int,int,int,int>current=q.front();
		q.pop();
		
		if(get<0>(current)==M-1&&get<1>(current)==N-1){
			return get<3>(current);
		}

		for(int i=0;i<5;i++){
			int nx=dx[i]+get<0>(current);
			int ny=dy[i]+get<1>(current);
			
			if(isval(nx,ny)){
				if(get<4>(current)==1){
					if(map[ny][nx]=='0'&&!visited[ny][nx][get<2>(current)]){
						q.push(make_tuple(nx,ny,get<2>(current),get<3>(current)+1,-get<4>(current)));
						visited[ny][nx][get<2>(current)]=1;
					}
					else if(map[ny][nx]=='1'&&get<2>(current)<K&&!visited[ny][nx][get<2>(current)+1]){
						q.push(make_tuple(nx,ny,get<2>(current)+1,get<3>(current)+1,-get<4>(current)));
						visited[ny][nx][get<2>(current)+1]=1;
					}
				}
				else if(get<4>(current)==-1){
					if(map[ny][nx]=='0'&&!visited[ny][nx][get<2>(current)]){
						q.push(make_tuple(nx,ny,get<2>(current),get<3>(current)+1,-get<4>(current)));
						visited[ny][nx][get<2>(current)]=1;
					}
					else if(map[ny][nx]=='1'&&(dx[i]!=0||dy[i]!=0)){
						if(visited[get<1>(current)][get<0>(current)][get<2>(current)]<2){
							q.push(make_tuple(get<0>(current),get<1>(current),get<2>(current),get<3>(current)+1,-get<4>(current)));
						}
						visited[get<1>(current)][get<0>(current)][get<2>(current)]++;
					}

					if(map[ny][nx]=='1'&&dx[i]==0&&dy[i]==0){
						if(visited[ny][nx][get<2>(current)]<2){
							q.push(make_tuple(nx,ny,get<2>(current),get<3>(current)+1,-get<4>(current)));
						}
						visited[ny][nx][get<2>(current)]++;
					}
				}
			}
		}
	}			
	return -1;	
}

int main(void){
	cin>>N>>M>>K;
	
	for(int i=0;i<N;i++){
		cin>>map[i];
	}

	int sol=bfs();
	
	if(sol==-1){
		cout<<-1<<endl;
	}
	else{
		cout<<sol<<endl;
	}
}
