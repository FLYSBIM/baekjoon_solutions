#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[100001];
int N,K;

vector<int> bfs(){
	queue<pair<int,int> >q;
	q.push(make_pair(N,0));
	visited[N]=1;
	vector<int>sol;
	sol.push_back(0);
	int toggle=0;
	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();
		
		if(current.first==K){
			if(!toggle){
				visited[current.first]++;
				sol[0]=current.second;
				toggle=1;
			}
			else if(toggle){
				if(current.second==sol[0]){
					visited[current.first]++;
				}
			}
		}

		if(current.first-1>=0&&!visited[current.first-1]){
			visited[current.first-1]=1;
			q.push(make_pair(current.first-1,current.second+1));
		}
	
		if(current.first<=2*(K-N)&&current.first+1<=100000&&!visited[current.first+1]){
			visited[current.first+1]=1;
			q.push(make_pair(current.first+1,current.second+1));
		}
		
		if(current.first*2<=2*(K-N)&&current.first*2<=100000&&!visited[current.first*2]){
			visited[current.first*2]=1;
			q.push(make_pair(current.first*2,current.second+1));
		}
		cout<<"c "<<current.first<<endl;
	}
	sol.push_back(visited[K]);
	return sol;
}

int main(void){
	cin>>N>>K;
	if(N>K){
		cout<<N-K<<endl;
		cout<<1<<endl;
		return 0;
	}
	else if(N==K){
		cout<<0<<endl;
		cout<<1<<endl;
		return 0;
	}
	else if(N<K){
		vector<int> sol=bfs();
		cout<<sol[0]<<endl;
		cout<<sol[1]<<endl;
	}
}
