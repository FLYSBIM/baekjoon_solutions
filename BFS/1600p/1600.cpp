#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int map[200][200]={0};
int visited[200][200][31]={0};
int K;
int W,H;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int horse_dx[8]={1,1,2,2,-1,-1,-2,-2};
int horse_dy[8]={2,-2,1,-1,2,-2,1,-1};

int bfs(){
	queue<tuple<int,int,int> >q;
	q.push(make_tuple(0,0,0));
	visited[0][0][0]=1;
	while(!q.empty()){
		tuple<int,int,int>current=q.front();
		q.pop();
	
		if(get<0>(current)==W-1&&get<1>(current)==H-1){
			return visited[get<1>(current)][get<0>(current)][get<2>(current)]-1;
		}
	
		for(int i=0;i<4;i++){
			int nx=dx[i]+get<0>(current);
			int ny=dy[i]+get<1>(current);
			
			if(nx>=0&&nx<W&&ny>=0&&ny<H&&map[ny][nx]==0&&!visited[ny][nx][get<2>(current)]){
				visited[ny][nx][get<2>(current)]=visited[get<1>(current)][get<0>(current)][get<2>(current)]+1;
				q.push(make_tuple(nx,ny,get<2>(current)));
			}
		}
		
		if(get<2>(current)<K){
			for(int i=0;i<8;i++){
				int nx=horse_dx[i]+get<0>(current);
				int ny=horse_dy[i]+get<1>(current);
			
				if(nx>=0&&nx<W&&ny>=0&&ny<H&&map[ny][nx]==0&&!visited[ny][nx][get<2>(current)+1]){
					visited[ny][nx][get<2>(current)+1]=visited[get<1>(current)][get<0>(current)][get<2>(current)]+1;
					q.push(make_tuple(nx,ny,get<2>(current)+1));
				}
			}
		}
	}
	return -1;
}

int main(void){
	cin>>K;
	cin>>W>>H;

	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin>>map[i][j];
		}
	}

	int sol=bfs();
	
	if(sol==-1){
		cout<<-1<<endl;
	}
	else{
		cout<<sol<<endl;
	}

}
	
