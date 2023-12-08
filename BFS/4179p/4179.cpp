#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[1000][1000];
int fvisited[1000][1000];
int jvisited[1000][1000];
int R,C;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int bfs(){
	queue<pair<int,int> >f;
	queue<pair<int,int> >ji;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(map[i][j]=='F'){
				f.push(make_pair(j,i));
				fvisited[i][j]=1;
			}
			else if(map[i][j]=='J'){
				ji.push(make_pair(j,i));
				jvisited[i][j]=1;
				if(i==0||i==R-1||j==0||j==C-1){
					return 1;
				}
			}	
		}
	}	

	int time=0;
	while(!ji.empty()){
		time++;
		int fsize=f.size();
		for(int j=0;j<fsize;j++){
			pair<int,int>currentf=f.front();
			f.pop();
			for(int i=0;i<4;i++){
				int nx=dx[i]+currentf.first;
				int ny=dy[i]+currentf.second;

				if(nx>=0&&nx<C&&ny>=0&&ny<R&&map[ny][nx]!='#'&&!fvisited[ny][nx]){
					f.push(make_pair(nx,ny));
					fvisited[ny][nx]=1;
					map[ny][nx]='F';
				}
			}
		}
		int jisize=ji.size();
		for(int j=0;j<jisize;j++){
			pair<int,int>currentj=ji.front();
			ji.pop();
			for(int i=0;i<4;i++){
				int nx=dx[i]+currentj.first;
				int ny=dy[i]+currentj.second;
			
				if(nx>=0&&nx<C&&ny>=0&&ny<R&&map[ny][nx]=='.'&&!jvisited[ny][nx]){
					ji.push(make_pair(nx,ny));	
					jvisited[ny][nx]=1;
					map[ny][nx]='J';
					if(nx==0||nx==C-1||ny==0||ny==R-1){
						time++;
						return time;
					}
				}
			}
		}
	}
	return 0;
}

int main(void){
	cin>>R>>C;
	for(int i=0;i<R;i++){
		cin>>map[i];
	}
	int a=bfs();
	if(a==0){
		cout<<"IMPOSSIBLE"<<endl;
	}
	else{
		cout<<a<<endl;
	}
}

