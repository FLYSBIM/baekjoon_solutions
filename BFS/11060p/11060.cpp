#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[1000];
int map[1000];
int N;


int bfs(){
	queue<pair<int,int> >q;
	q.push(make_pair(0,0));
	visited[0]=1;
	
	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();
	
		if(current.first==N-1){
			return current.second;
		}

		for(int i=1;i<=map[current.first];i++){
			if(current.first+i<N&&!visited[current.first]){
				q.push(make_pair(current.first+i,current.second+1));
				visited[current.first+i]=1;
			}
		}
	}
	return -1;
}

int main(void){
	cin>>N;

	for(int i=0;i<N;i++){
		cin>>map[i];
	}

	int sol=bfs();

	cout<<sol<<endl;
}
