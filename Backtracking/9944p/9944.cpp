#include <iostream>
#include <vector>

using namespace std;

char map[30][30];
int visited[30][30];
int N,M;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int sol=100000;

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

void backt(int x,int y,int k,int d){
	if(isvisit()){
		sol=min(sol,k);
		return ;
	}
/*
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<visited[i][j]<<" ";
		}
		cout<<endl;
	}*/
	int cnt=0;
	int nx=x+dx[d];
	int ny=y+dy[d];
	while(1){
		if(!isval(nx,ny)||map[ny][nx]=='*'||visited[ny][nx]==1){
			break;
		}
		visited[ny][nx]=1;
		nx+=dx[d];
		ny+=dy[d];
		cnt++;
	}
/*	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<visited[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"sol:"<<sol<<endl;*/

	nx-=dx[d];
	ny-=dy[d];
//	cout<<nx<<ny<<endl;
	for(int i=0;i<4;i++){
		if(isval(nx+dx[i],ny+dy[i])&&!visited[ny+dy[i]][nx+dx[i]]&&map[ny+dy[i]][nx+dx[i]]=='.'){
			backt(nx,ny,k+1,i);
		}
	}
	if(isvisit()){
		sol=min(sol,k+1);
	}
	while(cnt--){
		visited[ny][nx]=0;
		nx-=dx[d];
		ny-=dy[d];
	}
}		

int main(void){
	while(1){
	cin>>N>>M;
	initvisit();
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
		}
	}
	vector<pair<int,int> >v;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]=='.'&&isfron(j,i)){
				v.push_back(make_pair(j,i));
			}
		}
	}
	for(int i=0;i<v.size();i++){
		initvisit();
		visited[v[i].second][v[i].first]=1;
		for(int j=0;j<4;j++){
			backt(v[i].first,v[i].second,0,j);
		}
		visited[v[i].second][v[i].first]=0;
	}
	cout<<sol<<endl;
	}
}
