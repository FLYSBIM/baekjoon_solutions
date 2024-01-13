#include <iostream>
#include <vector>

using namespace std;

char map[100][100];
int n;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={1,0,-1,1,-1,1,-1,0};
int unknown(int x,int y);

int ismine(int x,int y){
	int mine=0;
	for(int i=0;i<8;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<n&&map[ny][nx]=='*'){
			mine++;
		}
	}
	return mine;
}	

void issafe(int x,int y,int minenum){
	if(minenum==0){
		for(int i=0;i<8;i++){
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<n&&map[ny][nx]=='#'){
				map[ny][nx]='S';
			}
		}
	}
	else if(minenum!=0&&unknown(x,y)+ismine(x,y)==minenum){
		if(ismine(x,y)!=minenum){
			for(int i=0;i<8;i++){
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(nx>=0&&nx<n&&ny>=0&&ny<n&&map[ny][nx]=='#'){
					map[ny][nx]='*';
				}
			}
		}
	}	
		if(ismine(x,y)==minenum){
			for(int i=0;i<8;i++){
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(nx>=0&&nx<n&&ny>=0&&ny<n&&map[ny][nx]=='#'){
					map[ny][nx]='S';
				}
			}
		}
	
}

int unknown(int x,int y){
	int unkn=0;
	for(int i=0;i<8;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<n&&map[ny][nx]=='#'){
			unkn++;
		}
	}
	return unkn;
}

int main(void){
	cin>>n;
	vector<vector<pair<int,int> > >v(9);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
			if(map[i][j]!='#'){
				v[map[i][j]-'0'].push_back(make_pair(j,i));
			}
		}
	}
	for(int i=0;i<=8;i++){
		for(int j=0;j<v[i].size();j++){
			issafe(v[i][j].first,v[i][j].second,map[v[i][j].second][v[i][j].first]-'0');
		}
	}	
	int sol=0;	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]=='#'||map[i][j]=='*'){
				sol++;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<map[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<sol<<endl;
}
	
