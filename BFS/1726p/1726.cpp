#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int map[100][100];

int M,N;
int dx[5]={1,-1,0,0};
int dy[5]={0,0,-1,1};

queue<tuple<int,int,int> >q;
int endx,endy,endd;

int bfs(){
	while(!q.emtpy()){
		tuple<int,int,int>current=q.front();
		int x=get<0>(current);
		int y=get<1>(current);
		int d=get<2>(current);
		q.pop();
		
		
}

int main(void){
	cin>>M>>N;

	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin>>map[i][j];
		}
	}

	int sx,sy,sd;
	cin>>sx>>sy>>sd;
	q.push(make_tuple(sx,sy,sd));

	cin>>endy>>endx>>endd;
}
	
