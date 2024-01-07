#include <iostream>
#include <vector>

using namespace std;

int map[10][10];
int visited1[30];
int visited2[30];
int N;
int sol=0;
vector<pair<int,int> >v;

void backt(int idx,int k){
	sol=max(sol,k);

	for(int i=idx;i<v.size();i++){
		if(map[v[i].second][v[i].first]&&!visited1[v[i].second+v[i].first]&&!visited2[v[i].first-v[i].second+N-1]){
			visited1[v[i].first+v[i].second]=1;
			visited2[v[i].first-v[i].second+N-1]=1;
			backt(i+1,k+1);
			visited1[v[i].first+v[i].second]=0;
			visited2[v[i].first-v[i].second+N-1]=0;
		}
	}
}

int main(void){
	cin>>N;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>map[i][j];
			v.push_back(make_pair(j,i));
		}
	}

	backt(0,0);

	cout<<sol<<endl;
}
