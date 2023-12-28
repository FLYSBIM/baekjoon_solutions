#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[100001];
int N,K;

vector<int> bfs(){
	queue<pair<int,vector<int> > >q;
	vector<int>a;
	a.push_back(N);
	q.push(make_pair(N,a));
	visited[N]=1;
	
	while(!q.empty()){
		pair<int,vector<int> >current=q.front();
		q.pop();

		if(current.first==K){
			vector<int>update=current.second;
			update.push_back(visited[current.first]-1);
			return update;
		}

		if(2*current.first<=100000&&!visited[current.first*2]){
			vector<int>update=current.second;
			update.push_back(2*current.first);
			q.push(make_pair(2*current.first,update));
			visited[2*current.first]=visited[current.first]+1;
		}

		if(current.first-1>=0&&!visited[current.first-1]){
			vector<int>update=current.second;
			update.push_back(current.first-1);
			q.push(make_pair(current.first-1,update));
			visited[current.first-1]=visited[current.first]+1;
		}

		if(current.first+1<=100000&&!visited[current.first+1]){
			vector<int>update=current.second;
			update.push_back(current.first+1);
			q.push(make_pair(current.first+1,update));
			visited[current.first+1]=visited[current.first]+1;
		}
	}	
	return a;
}

int main(void){
	cin>>N>>K;
	if(N>K){
		for(int i=N;i>=K;i--){
			cout<<i<<" ";
		}
		cout<<endl;
		cout<<N-K<<endl;
		return 0;
	}
	vector<int>sol=bfs();
	cout<<sol[sol.size()-1]<<endl;
	for(int i=0;i<sol.size()-1;i++){
		cout<<sol[i]<<" ";
	}
	cout<<endl;
}

	
