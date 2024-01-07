#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[20][20];
int N,M;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
queue<pair<int,int> >aa;
queue<pair<int,int> >bb;

int bfs(){
	pair<int,int>Astart=aa.front();
	pair<int,int>Bstart=bb.front();

	while(!aa.empty()||!bb.empty()){
		
}

int main(void){
	cin>>N>>M;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
			if(map[i][j]=='A'){
				aa.push(make_pair(j,i));
			}
			else if(map[i][j]=='B'){
				bb.push(make_pair(j,i));
			}
		}
	}
}
	
	
