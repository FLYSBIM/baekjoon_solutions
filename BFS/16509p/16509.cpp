#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[10][9];
int visited[10][9];
int R1,C1,R2,C2;
int dx[8]={2,2,3,3,-2,-2,-3,-3};
int dy[8]={3,-3,2,-2,3,-3,2,-2};

int isblock(int C1,int R1,int dx,int dy){
	if(dx==2&&dy==3){
		return map[R1+1][C1]||map[R1+2][C1+1];
	}
	else if(dx==-2&&dy==3){
		return map[R1+1][C1]||map[R1+2][C1-1];
	}
	else if(dx==-3&&dy==2){
		return map[R1][C1-1]||map[R1+1][C1-2];
	}
	else if(dx==-3&&dy==-2){
		return map[R1][C1-1]||map[R1-1][C1-2];
	}
	else if(dx==3&&dy==2){
		return map[R1][C1+1]||map[R1+1][C1+2];
	}
	else if(dx==3&&dy==-2){
		return map[R1][C1+1]||map[R1-1][C1+2];
	}
	else if(dx==-2&&dy==-3){
		return map[R1-1][C1]||map[R1-2][C1-1];
	}
	else if(dx==2&&dy==-3){
		return map[R1-1][C1]||map[R1-2][C1+1];
	}
	return 0;
}		

int bfs(){
	queue<pair<int,int> >q;
	q.push(make_pair(C1,R1));
	visited[R1][C1]=1;
	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();
		if(current.first==C2&&current.second==R2){
			return visited[current.second][current.first]-1;
		}
		for(int i=0;i<8;i++){
			int nx=dx[i]+current.first;
			int ny=dy[i]+current.second;
			
			if(nx>=0&&nx<9&&ny>=0&&ny<10&&!visited[ny][nx]&&1!=isblock(current.first,current.second,dx[i],dy[i])){
				q.push(make_pair(nx,ny));
				visited[ny][nx]=visited[current.second][current.first]+1;
			}
		}
	}
	return -1;
}

int main(void){
	cin>>R1>>C1;
	cin>>R2>>C2;

	map[R2][C2]=1;	

	int sol=bfs();

	if(sol==-1){
		cout<<-1<<endl;
	}
	else{
		cout<<sol<<endl;
	}
}
