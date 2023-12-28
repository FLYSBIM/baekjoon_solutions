#include <iostream>
#include <tuple>
#include <queue>
#include <cstdlib>

using namespace std;

int map[50][50];
int map2[50][50];
int visited[50][50];
int N,L,R;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int isval(int a,int b){
	return a>=0&&a<N&&b>=0&&b<N&&!visited[b][a];
}

int dif(int x1,int y1,int x2,int y2){
	return abs(map[y1][x1]-map[y2][x2])<=R&&abs(map[y1][x1]-map[y2][x2])>=L;
}

int bfs(){
	queue<tuple<int,int,int> >q;
	int comnum=1;
	for(int j=0;j<N;j++){
		for(int k=0;k<N;k++){
			if(!visited[j][k]){
				q.push(make_tuple(k,j,comnum));
				visited[j][k]=comnum;
				while(!q.empty()){
					tuple<int,int,int>current=q.front();
					q.pop();
					for(int i=0;i<4;i++){
						int nx=dx[i]+get<0>(current);
						int ny=dy[i]+get<1>(current);
				
						if(isval(nx,ny)&&dif(nx,ny,get<0>(current),get<1>(current))){
							q.push(make_tuple(nx,ny,get<2>(current)));
							visited[ny][nx]=get<2>(current);
						}
					}	
				}
				comnum++;		
			}
		}
	}	
	for(int k=1;k<=comnum;k++){
		int pou=0;
		int ucount=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(visited[i][j]==k){
					pou+=map[i][j];
					ucount++;
				}
			}
		}
		pou/=ucount;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(visited[i][j]==k){
					map[i][j]=pou;
					visited[i][j]=0;//g
				}
			}
		}
	}
	return 0;
}

int Iden(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(map[i][j]!=map2[i][j]){
				return 1;
			}
		}
	}
	return 0;
}

void resetvisited(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			visited[i][j]=0;
		}
	}
}

int main(void){
	cin>>N>>L>>R;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>map[i][j];
		}
	}
	int i=0;
	int stop=0;
	while(Iden()){
		//resetvisited();
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				map2[i][j]=map[i][j];
			}
		}
		bfs();
		i++;
		stop++;
		if(stop==500){
			break;
		}
	}
	cout<<i-1<<endl;
}
