#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[10000];
int A,B;

string bfs(){
	queue<pair<int,string> >q;
	q.push(make_pair(A,""));
	visited[A]=1;
	while(!q.empty()){
		pair<int,string>current=q.front();
		q.pop();
		
		if(current.first==B){
			return current.second;
		}

		if(2*current.first>9999&&!visited[2*current.first%10000]){
			q.push(make_pair(2*current.first%10000,current.second+'D'));
			visited[2*current.first%10000]=1;
		}
		else if(2*current.first<10000&&!visited[2*current.first]){
			q.push(make_pair(2*current.first,current.second+'D'));
			visited[2*current.first]=1;
		}

		if(current.first==0&&!visited[9999]){
			q.push(make_pair(9999,current.second+'S'));
			visited[9999]=1;
		}
		else if(current.first>0&&!visited[current.first-1]){
			q.push(make_pair(current.first-1,current.second+'S'));
			visited[current.first-1]=1;
		}
		
		if(!visited[current.first/1000+current.first%1000*10]){
			q.push(make_pair(current.first/1000+current.first%1000*10,current.second+'L'));
			visited[current.first/1000+current.first%1000*10]=1;
		}
		
		if(!visited[current.first/10+current.first%10*1000]){
			q.push(make_pair(current.first/10+current.first%10*1000,current.second+'R'));
			visited[current.first/10+current.first%10*1000]=1;
		}	
	}
	return "A";
}

void initvisited(){
	for(int i=0;i<10000;i++){
		visited[i]=0;
	}
}

int main(void){
	int T=0;
	cin>>T;
	while(T--){
		cin>>A>>B;
			
		string sol=bfs();
		
		cout<<sol<<endl;
		initvisited();
	}
}
