#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int>v;
vector<int>v2;

int main(void){
	
	cin>>N;

	for(int i=0;i<N;i++){
		int M;
		cin>>M;
		v.push_back(M);
		v2.push_back(M);
	}

	sort(v.rbegin(),v.rend());
	sort(v2.rbegin(),v.rend());

	while(!v.empty()){
		int current=pq.top();
		pq.pop();
		M[current]=1;
		v.pop_back();
		for(int i=0;i<v.size();i++){
			M[current+v[i]]=1;
					

		for(int i=0;
}
