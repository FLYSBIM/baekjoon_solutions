#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

char map[100][100]={0};
int key[26];
int visited[100][100]={0};
int h,w;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int count$=0;
int bfs(){
	queue<pair<int,int> >S;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(i==0||i==h-1||j==0||j==w-1){
				if(map[i][j]=='.'||map[i][j]=='$'){
					S.push(make_pair(j,i));
					visited[i][j]=1;
					if(map[i][j]=='$'){
						count$++;
					}
				}
			}
		}
	}
	
	while(!S.empty()){
		pair<int,int>current=S.front();
		S.pop();
		for(int i=0;i<4;i++){
			int nx=dx[i]+current.first;
			int ny=dy[i]+current.second;
			
			if(nx>=0&&nx<w-1&&ny>=0&&ny<h-1&&(map[ny][nx]=='.'||map[ny][nx]=='$')&&!visited[ny][nx]){
				S.push(make_pair(nx,ny));
				visited[ny][nx]=1;
				if(map[ny][nx]=='$'){
					count$++;
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
		cin>>h>>w;
		count$=0;
		for(int j=0;j<h;j++){
			for(int k=0;k<w;k++){
				visited[j][k]=0;
			}
		}
		for(int j=0;j<26;j++){
			key[j]=0;
		}

		for(int j=0;j<h;j++){
			cin>>map[j];
		}
		char keys[100]="";
		cin>>keys;
		
		for(int j=0;j<strlen(keys);j++){
			key[keys[j]-'a']=1;
		}
		cout<<strlen(keys)<<"aa\n";
			
		for(int j=0;j<h;j++){
			for(int k=0;k<w;k++){
				if(map[j][k]-'A'>=0&&key[(map[j][k]-'A')]==1){
					map[j][k]='.';
				}
			}
		}
		bfs();
		for(int j=0;j<h;j++){
			cout<<map[j]<<endl;
		}
		cout<<count$<<endl;
	}
}
