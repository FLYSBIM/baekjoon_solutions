#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[100][100];
int visited[100][100];
int H,W;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int bfs(){
	queue<pair<int,int> >q;
	q.push(make_pair(0,0));
	visited[0][0]=1;
	
	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();

		for(int i=0;i<4;i++){
			int nx=dx[i]+current.first;
			int ny=dy[i]+current.second;
	
			if(nx>=0&&nx<W&&ny>=0&&ny<H){
				if(!visited[ny][nx]&&map[ny][nx]==0){
					q.push(make_pair(nx,ny));
					visited[ny][nx]=1;
				}
				else if(!visited[ny][nx]&&map[ny][nx]==1){
					visited[ny][nx]=1;
				}
			}
		}
	}
	return 0;			
}

int isCheese(){
	int Cnum=0;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(map[i][j]==1){
				Cnum++;
			}
		}
	}
	return Cnum;
}

void melt(){
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(map[i][j]==1&&visited[i][j]){
				map[i][j]=0;
			}
			visited[i][j]=0;
		}
	}
}

int main(void){
	cin>>H>>W;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin>>map[i][j];
		}
	}
	int sol=0;
	int time=0;
	while(1){
		bfs();
		sol=isCheese();
		melt();
		time++;
		if(isCheese()==0){
			break;
		}
	}
	cout<<time<<endl;
	cout<<sol<<endl;
}
