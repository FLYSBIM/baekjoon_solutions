#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long long A,B;

int bfs(){
	queue<pair<long long ,int> >q;
	q.push(make_pair(A,1));
	
	while(!q.empty()){
		pair<long long,int>current=q.front();
		q.pop();
		
		if(current.first==B){
			return current.second;
		}
		
		if(current.first*2<=B){
			q.push(make_pair(current.first*2,current.second+1));
		}
		
		if(current.first*10+1<=B){
			q.push(make_pair(current.first*10+1,current.second+1));
		}
	}
	return -1;
}


int main(void){
	cin>>A>>B;
	
	int sol=bfs();
	
	if(sol==-1){
		cout<<-1<<endl;
	}
	else{
		cout<<sol<<endl;
	}
}
	
