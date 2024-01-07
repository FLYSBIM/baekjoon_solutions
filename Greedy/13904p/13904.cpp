#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main(void){
	priority_queue<pair<int,int> > pq;

	cin>>N;

	int d,w;
	for(int i=0;i<N;i++){
		cin>>d>>w;
		pq.push(make_pair(d,w));
	}
}
