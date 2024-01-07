#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[6][6];
int N;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
vector<pair<int,int> >v;
int toggle=0;
vector<pair<int,int> >t;

int isval(int x,int y){
	return x>=0&&x<N&&y>=0&&y<N;
}

int isfron(int x,int y){
	for(int i=0;i<4;i++){
		int nx=dx[i]+x;
		int ny=dy[i]+y;
		if(nx>=0&&nx<N&&ny>=0&&ny<N&&map[ny][nx]=='T'){
			return 1;
		}
	}
	return 0;
}

int watch(int x,int y,int d){
	while(1){
		x+=dx[d];
		y+=dy[d];
		if(!isval(x,y)){
			break;
		}
		if(isval(x,y)){
			if(map[y][x]=='S'){
				return 1;
			}
			else if(map[y][x]=='O'){
				return 0;
			}
		}
	}
	return 0;
}

int Teacher(){
	for(int i=0;i<t.size();i++){
		for(int j=0;j<4;j++){
			if(watch(t[i].first,t[i].second,j)){
				return 0;
			}
		}
	}
	return 1;
}		

int backt(int idx,int k){
	if(k==3){
		if(Teacher()){
			toggle=1;
			return 1;
		}
	}
	
	for(int i=idx;i<v.size();i++){
		map[v[i].second][v[i].first]='O';
		backt(i+1,k+1);
		map[v[i].second][v[i].first]='X';
	}
	return 1;
}
int main(void){
	cin>>N;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>map[i][j];
		}
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(isfron(j,i)&&map[i][j]=='X'){
				v.push_back(make_pair(j,i));
			}
			else if(map[i][j]=='T'){
				t.push_back(make_pair(j,i));
			}
		}
	}
	backt(0,0);
	if(toggle){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}
