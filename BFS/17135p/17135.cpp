#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N,M,D;
int tempmap[16][15];
int map[16][15];
int visited[16][15];
int dx[3]={-1,0,1};
int dy[3]={0,1,0};
int sol=0;
/*
void nextturn(){
	for(int i=N-1;i>0;i--){
		for(int j=0;j<M;j++){
			if(tempmap[i-1][j]==2){
				tempmap[i-1][j]=0;
			}
			tempmap[i][j]=tempmap[i-1][j];
		}
	}
	for(int i=0;i<M;i++){
		tempmap[0][i]=0;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			visited[i][j]=0;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<tempmap[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}*/

void nextturn() {
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < M; j++) {
            // 이전 행에서 해당 블록이 2로 설정되어 있으면 0으로 설정
            if (tempmap[i - 1][j] == 2) {
                tempmap[i - 1][j] = 0;
            }
            // 현재 행의 해당 블록을 이전 행의 같은 열 값으로 설정
            tempmap[i][j] = tempmap[i - 1][j];
        }
    }
    for (int i = 0; i < M; i++) {
        // 이전 행의 해당 열이 2로 설정되어 있으면 0으로 설정
        if (tempmap[N - 1][i] == 2) {
            tempmap[N - 1][i] = 0;
        }
        // 현재 행의 해당 열을 이전 행의 같은 열 값으로 설정
        tempmap[0][i] = tempmap[N - 1][i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << tempmap[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
			

int bfs(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			tempmap[i][j]=map[i][j];
		}	
	}
	int kill=0;
	while(N--){
		queue<pair<int,int> >q;
		for(int i=0;i<M;i++){
			if(tempmap[N][i]==2){
				q.push(make_pair(i,N));
				visited[N][i]=1;
			}
		}
		while(!q.empty()){
		        int Qsize=q.size();
			for(int j=0;j<Qsize;j++){
				int but=1;		
				pair<int,int>current=q.front();
				q.pop();
	
				for(int i=0;i<3;i++){
					int nx=dx[i]+current.first;
					int ny=dy[i]+current.second;
			
					if(but&&nx>=0&&nx<M&&ny>=0&&ny<N&&!visited[ny][nx]){
						if(tempmap[ny][nx]==1&&visited[current.second][current.first]<=D){
							tempmap[ny][nx]=2;
							visited[ny][nx]=visited[current.second][current.first]+1;
							kill++;
							but=0;
						}
						else if(tempmap[ny][nx]==0&&visited[current.second][current.first]<=D){
							q.push(make_pair(nx,ny));
							visited[ny][nx]=visited[current.second][current.first]+1;
						}
					}
				}
			}
		}
		nextturn();
	}				
	return kill;				
}

void arc(int k){
	if(k==3){
		int enemy=bfs();
		sol=max(enemy,sol);
		return ;
	}

	for(int i=0;i<M;i++){
		if(map[N][i]==0){
			map[N][i]=2;
			arc(k+1);
			map[N][i]=0;
		}
	}
}

int main(void){
	cin>>N>>M>>D;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
		}
	}

	arc(0);
	cout<<sol<<endl;
}

