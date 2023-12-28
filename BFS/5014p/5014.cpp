#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[1000001];
int F,S,G,U,D;

int bfs(){
	queue<pair<int,int> >q;
	q.push(make_pair(S,0));
	visited[S]=1;
	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();
		
		if(current.first==G){
			return visited[current.first]-1;
		} 		
	
		if(U+current.first<=F&&!visited[current.first+U]){
			q.push(make_pair(current.first+U,current.second+1));
			visited[current.first+U]=visited[current.first]+1;
		}
 		
		if(current.first-D>=1&&!visited[current.first-D]){
			q.push(make_pair(current.first-D,current.second+1));
			visited[current.first-D]=visited[current.first]+1;
		}
	}
	return -1;
}

int main(){
	cin>>F>>S>>G>>U>>D;
	int sol=bfs();
	if(sol==-1){
		cout<<"use the stairs"<<endl;
	}
	else{
		cout<<sol<<endl;
	}
}
