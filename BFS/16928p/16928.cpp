#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int graph[101][101];
int visited[101];
int N,M;

int bfs(){
	visited[1]=1;
	queue<int>q;
	q.push(1);
	
	while(!q.empty()){
		int current=q.front();
		q.pop();
		
		if(current==100){
			return visited[current]-1;
		}
		comcurrent=current;
		for(int i=1;i<=6;i++){
			for(int j=2;j<=99;j++){
				if(graph[comcurrent+i][j]==1){
					q.push(j);
					visited[j]=visited[comcurrent]+1;
					
				}
			}
			if(!visited[current+i]){
				q.push(current+i);
				visitied[current+i]=visited[current]+1;
			}
		}
	}
	return -1;
}

int main(void){
	cin>>N>>M;
	int x,y;
	for(int i=0;i<N+M;i++){
		cin>>x>>y;
		graph[x][y]=1;
	}
	
	int sol=bfs();
	cout<<sol<<endl;
}
