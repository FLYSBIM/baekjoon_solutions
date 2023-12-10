#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[1000][1000]={0};
int visitedS[1000][1000]={0};
int visitedF[1000][1000]={0};
int w,h;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int bfs(){
	queue<pair<int,int> >F;
	queue<pair<int,int> >S;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(map[i][j]=='*'){
				F.push(make_pair(j,i));
				visitedF[i][j]=1;
			}
			else if(map[i][j]=='@'){
				S.push(make_pair(j,i));
				visitedS[i][j]=1;
				if(j==0||j==w-1||h==0||h==h-1){
					return 1;
				}
			}
		}
	}
	while(!S.empty()){
		int Fsize=F.size();
		for(int i=0;i<Fsize;i++){
			pair<int,int>currentF=F.front();
			F.pop();
			for(int j=0;j<4;j++){
				int nx=dx[j]+currentF.first;
				int ny=dy[j]+currentF.second;
					
				if(nx>=0&&nx<w&&ny>=0&&ny<h&&map[ny][nx]!='#'&&!visitedF[ny][nx]){
					F.push(make_pair(nx,ny));
					visitedF[ny][nx]=1;
					map[ny][nx]='*';
				}
			}
		}
		int Ssize=S.size();
		for(int i=0;i<Ssize;i++){
			pair<int,int>currentS=S.front();
			S.pop();
			for(int j=0;j<4;j++){
				int nx=dx[j]+currentS.first;
				int ny=dy[j]+currentS.second;
				
				if(nx>=0&&nx<w&&ny>=0&&ny<h&&map[ny][nx]=='.'&&!visitedS[ny][nx]){
					S.push(make_pair(nx,ny));
					visitedS[ny][nx]=visitedS[currentS.second][currentS.first]+1;
					if(nx==0||nx==w-1||ny==0||ny==h-1){
						return visitedS[ny][nx];
					}
					map[ny][nx]='@';
				}
			}
		}
	}
	return 0;
}

int main(void){
	int T=0;
	cin>>T;
	
	for(int i=0;i<T;i++){
		cin>>w>>h;
	

		for(int i=0;i<h;i++){
			cin>>map[i];
		}
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				visitedF[i][j]=0;
				visitedS[i][j]=0;
			}
		}

		int sol=bfs();
		
		if(sol==0){
			cout<<"IMPOSSIBLE"<<endl;
		}
		else{
			cout<<sol<<endl;
		}
	}
	return 0;
}
