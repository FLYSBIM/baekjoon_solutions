#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int map[20][20];
int visited[20][20];
int N,M,E;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int X1,Y1;

int bfs(){
	
}

int main(void){
	cin>>N>>M>>E;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>map[i][j];
		}
	}
	
	cin>>Y1>>X1;	

	int sx,sy,ex,ey;
	for(int i=2;i<M+2;i++){
		cin>>sy>>sx>>ey>>ex;
		map[sy-1][sx-1]=i;
		map[ey-1][ex-1]=i;
	}

}
