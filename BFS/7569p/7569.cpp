#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int map[100][100][100];
int visited[100][100][100];
int M,N,H;
int dx[6]={1,-1,0,0,0,0};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

int bfs(){
	queue<tuple<int,int,int>>q;
	for(int i=0;i<H;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<M;k++){
				if(map[i][j][k]==1){
					q.push(make_tuple(k,j,i));
					visited[i][j][k]=1;
				}
			}
		}
	}
	int time=0;
	while(!q.empty()){
		int Qsize=q.size();
		for(int j=0;j<Qsize;j++){
			tuple<int,int,int>current=q.front();
			q.pop();

			for(int i=0;i<6;i++){
				int nx=dx[i]+get<0>(current);
				int ny=dy[i]+get<1>(current);
				int nz=dz[i]+get<2>(current);
			
				if(nx>=0&&nx<M&&ny>=0&&ny<N&&nz>=0&&nz<H&&!visited[nz][ny][nx]&&map[nz][ny][nx]==0){
					q.push(make_tuple(nx,ny,nz));
					map[nz][ny][nx]=1;
					visited[nz][ny][nx]=1;
				}
			}
		}
		time++;
	}
	return time-1;
}

int main(void){
	
	cin>>M>>N>>H;
	
	for(int i=0;i<H;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<M;k++){
				cin>>map[i][j][k];
			}
		}
	}

	int sol=bfs();

	for(int i=0;i<H;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<M;k++){
				if(map[i][j][k]==0){
					cout<<-1<<endl;
					return 0;
				}
			}
		}
	}
	
	if(sol==-1){
		cout<<-1<<endl;
	}
	else{
		cout<<sol<<endl;
	}
}
