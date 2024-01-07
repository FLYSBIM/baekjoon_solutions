#include <iostream>
#include <vector>

using namespace std;

int map[500][500];
int used[500][500];
int N,M;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<pair<int,int> >v;
int sol=0;
int tetsum=0;
void sub(int k,int x,int y){
	if(k==1){
		tetsum=0;
		for(int i=0;i<4;i++){
                        tetsum+=map[v[i].second][v[i].first];
			cout<<"xy"<<v[i].first<<" "<<v[i].second<<endl;
                }
		return ;
	}
	
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(nx>=0&&nx<M&&ny>=0&&ny<N&&!used[ny][nx]){
			used[ny][nx]=1;
			v.push_back(make_pair(nx,ny));
			sub(k+1,nx,ny);
			v.pop_back();
			used[ny][nx]=0;
		}
	}	
}

void tet(int k,int x,int y){
	if(k==3){
		for(int i=0;i<3;i++){
			sub(0,v[i].first,v[i].second);
			sol=max(sol,tetsum);
		}
		return ;
	}
	
	v.push_back(make_pair(x,y));
	used[y][x]=1;
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0&&nx<M&&ny>=0&&ny<N&&!used[ny][nx]){
			tet(k+1,nx,ny);
		}
	}
	v.pop_back();
	used[y][x]=0;
}
			

int main(void){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			tet(0,j,i);
		}
	}

	cout<<sol<<endl;
}
