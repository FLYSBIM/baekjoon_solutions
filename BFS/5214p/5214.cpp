#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited[1001];
int N,K,M;
vector<vector<int> >v;

int bfs(){
	queue<int>q;
	q.push(1);
	visited[1]=1;

	while(!q.empty()){
		int current=q.front();
		q.pop();

		if(current==N){
			return visited[current];
		}

		for(int i=0;i<v[current].size();i++){
			if(!visited[v[current][i]]){
				q.push(v[current][i]);
				visited[v[current][i]]=visited[current]+1;
			}
		}
	}
	return -1;
}		

int main(void){
	cin>>N>>K>>M;

	vector<int>temp(K);
	v.resize(N+1);
	for(int i=0;i<M;i++){
		int mi=1000000;
		for(int j=0;j<K;j++){
			cin>>temp[j];
			mi=min(mi,tempj]);
		}
		
		for(int j=0;j<K;j++){
			for(int k=0;k<K;k++){
				if(k!=j){
					v[temp[j]].push_back(temp[k]);
				}
			}
		}
	}
	int sol=bfs();
	cout<<sol<<endl;
}
