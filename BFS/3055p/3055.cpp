#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[50][50];
int visitedS[50][50]={0};
int visitedW[50][50]={0};
int R,C;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int bfs(){
	queue<pair<int,int> >S;
	queue<pair<int,int> >W;
	
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(map[i][j]=='*'){
				W.push(make_pair(j,i));
				visitedW[i][j]=1;
			}
			else if(map[i][j]=='S'){
				S.push(make_pair(j,i));
				visitedS[i][j]=1;
			}
		}
	}

	while(!S.empty()){
		int Wsize=W.size();
		for(int i=0;i<Wsize;i++){
			pair<int,int>currentW=W.front();
			W.pop();
			for(int j=0;j<4;j++){
				int nx=dx[j]+currentW.first;
				int ny=dy[j]+currentW.second;
				
				if(nx>=0&&nx<C&&ny>=0&&ny<R&&map[ny][nx]=='.'&&!visitedW[ny][nx]){
					W.push(make_pair(nx,ny));
					visitedW[ny][nx]=1;
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
				
				if(nx>=0&&nx<C&&ny>=0&&ny<R&&map[ny][nx]!='X'&&map[ny][nx]!='*'&&!visitedS[ny][nx]){
					S.push(make_pair(nx,ny));
					if(map[ny][nx]=='D'){
						return visitedS[currentS.second][currentS.first];
					}
					visitedS[ny][nx]=visitedS[currentS.second][currentS.first]+1;
					map[ny][nx]='S';
				}
			}
		}
	}
	return 0;	
}

int main(void){
	scanf("%d%d",&R,&C);

	for(int i=0;i<R;i++){
		cin>>map[i];
	}
	int sol=bfs();
	if(sol==0){
		cout<<"KAKTUS"<<endl;
	}
	else{
		cout<<sol<<endl;
	}
}
