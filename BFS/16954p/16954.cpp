#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char map[8][8];
int visited[8][8];
int dx[9]={1,1,1,0,0,0,-1,-1,-1};
int dy[9]={0,1,-1,1,-1,0,-1,0,1};

void walldown(){
	for(int i=7;i>=1;i--){
		for(int j=0;j<8;j++){
			map[i][j]=map[i-1][j];
		}
	}
	for(int i=0;i<8;i++){
		map[0][i]='.';
	}
}

int bfs(){
	queue<pair<int,int> >q;
	q.push(make_pair(0,7));
	visited[7][0]=1;

	while(!q.empty()){
		int size=q.size();
		while(size--){
		pair<int,int>current=q.front();
		q.pop();
		

		if(current.first==7&&current.second==0){
			return 1;
		}
		for(int i=0;i<9;i++){
			int nx=dx[i]+current.first;
			int ny=dy[i]+current.first;
			
			if(nx>=0&&nx<8&&ny>=0&&ny<8&&map[ny][nx]!='#'){
					q.push(make_pair(nx,ny));
					visited[ny][nx]++;
			}
		}
		}
		walldown();
	}
	return -1;
}

int main(void){
	for(int i=0;i<8;i++){
		cin>>map[i];
	}

	int sol=bfs();
	if(sol==1){
		cout<<1<<endl;
	}
	else if(sol==-1){
		cout<<0<<endl;
	}
}
	
