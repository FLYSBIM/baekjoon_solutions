#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char map[1000][1000];
int visited[1000][1000];
int H,W;
int dx[8]={1,1,1,0,0,-1,-1,-1};
int dy[8]={1,0,-1,1,-1,1,0,-1};
int melt();

int isfro(int x,int y){
	if(map[y][x]=='.'){
		for(int i=0;i<8;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx>=0&&nx<W&&ny>=0&&ny<H&&map[ny][nx]!='.'){
				return 1;
			}
		}
	}
	return 0;
}		

int bfs(){
	queue<pair<int,int> >q;
	
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			visited[i][j]=0;
			if(isfro(j,i)){
				q.push(make_pair(j,i));
				visited[i][j]=1;
			}
		}
	}

	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();

		for(int i=0;i<8;i++){
			int nx=dx[i]+current.first;
			int ny=dy[i]+current.second;
			
			if(nx>=0&&nx<W&&ny>=0&&ny<H){
				if(map[ny][nx]!='.'){
					visited[ny][nx]++;
				}
			}
		}
	}
	int sol=melt();
	if(sol==1){
		return 1;
	}
	return 0;	
}

int melt(){
	int but=0;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(map[i][j]!='.'&&visited[i][j]>=map[i][j]-'0'){
				map[i][j]='.';
				but=1;
			}
		}
	}
	if(but){
		return 1;
	}
	return 0;
}

int main(void){
	cin>>H>>W;

	for(int i=0;i<H;i++){
		cin>>map[i];
	}
	int prob=1;
	int sol=0;
	while(prob){
		prob=bfs();
		sol++;
	}
	cout<<sol-1<<endl;
}		
