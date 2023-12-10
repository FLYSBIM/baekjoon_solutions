#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

char map[30][30][30]={0};
int visited[30][30][30]={0};
int L,R,C;
int dx[6]={0,0,0,0,1,-1};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={1,-1,0,0,0,0};

int bfs(){
	queue<tuple<int,int,int> >q;
	for(int i=0;i<L;i++){
		for(int j=0;j<R;j++){
			for(int k=0;k<C;k++){
				if(map[i][j][k]=='S'){
					q.push(make_tuple(i,j,k));
					visited[i][j][k]=1;
				}
			}
		}
	}
	
	while(!q.empty()){
		tuple<int,int,int>current=q.front();
		q.pop();
		for(int i=0;i<6;i++){
			int nx=dx[i]+get<2>(current);
			int ny=dy[i]+get<1>(current);
			int nz=dz[i]+get<0>(current);
			
			if(nx>=0&&nx<C&&ny>=0&&ny<R&&nz>=0&&nz<L&&map[nz][ny][nx]!='#'&&!visited[nz][ny][nx]){
				q.push(make_tuple(nz,ny,nx));
				visited[nz][ny][nx]=visited[get<0>(current)][get<1>(current)][get<2>(current)]+1;
				if(map[nz][ny][nx]=='E'){
					return visited[nz][ny][nx];
				}
			}
		}
	}
	return 0;
}

int main(void){
	L=1,R=1,C=1;

	while(1){
		cin>>L>>R>>C;
		if(L==0&&R==0&&C==0){
			break;
		}
		for(int i=0;i<L;i++){
			for(int j=0;j<R;j++){
				for(int k=0;k<C;k++){
					visited[i][j][k]=0;
				}
			}
		}	
		for(int i=0;i<L;i++){
			for(int j=0;j<R;j++){
				cin>>map[i][j];
			}
		}
		int sol=bfs();
		if(sol==0){
			cout<<"Trapped!"<<endl;
		}
		else{
			cout<<"Escaped in "<<sol-1<<" minute(s)."<<endl;
		}
	}

}
