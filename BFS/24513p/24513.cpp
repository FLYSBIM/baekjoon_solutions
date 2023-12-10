#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[1000][1000]={0};
int visited1[1000][1000]={0};
int visited2[1000][1000]={0};
int N,M;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int bfs(){
	queue<pair<int,int> >V;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]==1){
				V.push(make_pair(j,i));
				visited1[i][j]=1;
			}
			else if(map[i][j]==2){
				V.push(make_pair(j,i));
				visited2[i][j]=1;
			}
		}
	}

	while(!V.empty()){
		pair<int,int>current=V.front();
		V.pop();
		for(int i=0;i<4;i++){
			int nx=dx[i]+current.first;
			int ny=dy[i]+current.second;
			
			if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[current.second][current.first]!=3&&map[ny][nx]!=-1){
				if(map[ny][nx]==1&&map[current.second][current.first]==2){
					if((visited2[current.second][current.first]+1)==visited1[ny][nx]){
						map[ny][nx]=3;
						visited2[ny][nx]=visited1[ny][nx];
					}
				}
				else if(map[ny][nx]==2&&map[current.second][current.first]==1){
					if((visited1[current.second][current.first]+1)==visited2[ny][nx]){
						map[ny][nx]=3;
						visited1[ny][nx]=visited2[ny][nx];
					}
				}
				else if(map[current.second][current.first]==1&&map[ny][nx]==0){
					V.push(make_pair(nx,ny));
					map[ny][nx]=map[current.second][current.first];
					visited1[ny][nx]=visited1[current.second][current.first]+1;
				}	
				else if(map[current.second][current.first]==2&&map[ny][nx]==0){
					V.push(make_pair(nx,ny));
					map[ny][nx]=map[current.second][current.first];
					visited2[ny][nx]=visited2[current.second][current.first]+1;
				}	
			}
		}
	}
	return 0;
}
int main(void){
	cin>>N>>M;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
		}
	}

	bfs();
	int count1=0;
	int count2=0;
	int count3=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(map[i][j]==1){
				count1++;
			}
			else if(map[i][j]==2){
				count2++;
			}
			else if(map[i][j]==3){
				count3++;
			}
		}
	}
	cout<<count1<<" "<<count2<<" "<<count3<<endl;
}
