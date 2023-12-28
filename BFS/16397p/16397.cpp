#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[100000];
int N,T,G;

int bfs(){
	queue<pair<int,int> >q;
	q.push(make_pair(N,0));
	visited[N]=1;
	
	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();
		
		
		if(current.first==G){
			return current.second;
		}

		if(current.second==T){
			return -1;
		}
		if(current.first+1<100000&&!visited[current.first+1]){
			q.push(make_pair(current.first+1,current.second+1));
			visited[current.first+1]=1;
		}

		
		if(2*current.first<100000&&2*current.first>=10000&&!visited[2*current.first-10000]){
			q.push(make_pair(2*current.first-10000,current.second+1));
			int a=2*current.first-10000;
			if(a>=0){
				visited[2*current.first-10000]=1;
			}
		}
		else if(2*current.first<10000&&2*current.first>=1000&&!visited[2*current.first-1000]){
			q.push(make_pair(2*current.first-1000,current.second+1));
			int a=2*current.first-1000;
                        if(a>=0){
                                visited[2*current.first-1000]=1;
                        }
		}
		else if(2*current.first<1000&&2*current.first>=100&&!visited[2*current.first-100]){
			q.push(make_pair(2*current.first-100,current.second+1));
		//	visited[2*current.first-100]=1;
			int a=2*current.first-100;
                        if(a>=0){
                                visited[2*current.first-100]=1;
                        }
		}
		else if(2*current.first<100&&2*current.first>=10&&!visited[2*current.first-10]){
			q.push(make_pair(2*current.first-10,current.second+1));
		//	visited[2*current.first-10]=1;
			int a=2*current.first-10;
                        if(a>=0){
                                visited[2*current.first-10]=1;
                        }
		}
		else if(2*current.first<10&&2*current.first>=0&&!visited[2*current.first-1]){
			q.push(make_pair(2*current.first-1,current.second+1));
		//	visited[2*current.first-1]=1;
			int a=2*current.first-1;
                        if(a>=0){
                                visited[2*current.first-1]=1;
                        }
		}
	}
	return -1;
}

int main(void){
	cin>>N>>T>>G;
	
	if(N==G){
		cout<<0<<endl;
		return 0;
	}

	int sol=bfs();
	

	if(sol==-1){
		cout<<"ANG"<<endl;
	}
	else{
		cout<<sol<<endl;
	}
}
