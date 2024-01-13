#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void){
	int N;
	cin>>N;
	vector<pair<int,int> >v(N);
	int des,ene;
	priority_queue<int>pq;

	for(int i=0;i<N;i++){
		cin>>v[i].first>>v[i].second;
	}
	sort(v.rbegin(),v.rend());

	cin>>des>>ene;
	int loca=ene;
	int sol=0;

	while(!v.empty()){
		int toggle=1;
		if(loca>=des){
			break;
		}
		
		while(!v.empty()){
			pair<int,int>current=v.back();
			if(loca>=current.first){
				toggle=0;
				pq.push(current.second);
				v.pop_back();
			}
			else if(loca<current.first){
				break;
			}
		}
		
		if(!pq.empty()){
			int oil=pq.top();
			loca+=oil;
			pq.pop();
			sol++;
		}
		else if(pq.empty()&&toggle){
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<sol<<endl;		
}
