#include <iostream>
#include <vector>

using namespace std;

char map[30][30];
int visited[30][30];
int N,M;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int sol=100000;
vector<pair<int,int> >v;

int isval(int x,int y){
	return x>=0&&x<M&&y>=0&&y<N;
}

int isfron(int x,int y){
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];

		if(isval(nx,ny)&&map[ny][nx]=='*'){
			return 1;
		}
	}
	return 0;
}

void initvisit(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			visited[i][j]=0;
		}
	}
}

int isvisit(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]=='.'&&visited[i][j]==0){
				return 0;
			}
		}
	}
	return 1;
}

void backt(int x,int y,int k){
	if(isvisit()){
		sol=min(sol,k);
		return ;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<visited[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"k:xy"<<k<<" "<<x<<y<<endl;
	for(int i=0;i<4;i++){
		int tx=x;
		int ty=y;
		int idx=0;
		if(isval(x+dx[i],y+dy[i])&&map[y+dy[i]][x+dx[i]]=='.'&&!visited[y+dy[i]][x+dx[i]]){
			while(isval(tx,ty)&&map[ty][tx]=='.'&&!visited[ty][tx]){
				visited[ty][tx]=1;
				tx+=dx[i];
				ty+=dy[i];
				idx++;
			}
			cout<<tx<<ty<<endl;
			backt(tx-dx[i],ty-dy[i],k+1);
			for(int i=0;i<idx;i++){
				visited[ty-dx[i]][tx-dy[i]]=0;
				tx-=dx[i];
				ty-=dy[i];
			}
		}
	}
}		

int main(void){
	cin>>N>>M;

	for(int i=0;i<N;i++){
		cin>>map[i];
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]=='.'&&isfron(j,i)){
				v.push_back(make_pair(j,i));
			}
		}
	}
	backt(2,0,0);
/*	for(int i=0;i<v.size();i++){
		initvisit();
		visited[v[i].second][v[i].first]=1;
		backt(v[i].first,v[i].second,0);
	}*/
}
