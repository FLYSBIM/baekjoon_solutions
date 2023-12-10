#include <iostream>
#include <queue>

using namespace std;

int visited[100001]={0};
int N,K;

int bfs(int x){
	queue<int>q;
	q.push(x);
	visited[x]=1;
	while(!q.empty()){
		int current=q.front();
		q.pop();
		
		if(current==K){
			return visited[current]-1;
		}

		if(current-1>=0&&!visited[current-1]){
			q.push(current-1);
			visited[current-1]=visited[current]+1;
		}

		if(current+1<=100000&&!visited[current+1]){
			q.push(current+1);
			visited[current+1]=visited[current]+1;
		}

		if(current*2<=100000&&!visited[current*2]){
			q.push(current*2);
			visited[current*2]=visited[current]+1;
		}
	}
	return -1;
}

int main(){
	cin>>N>>K;
	int sol=bfs(N);
	cout<<sol<<endl;
}
