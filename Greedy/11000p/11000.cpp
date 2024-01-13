#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

int main(void){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >TS;
	priority_queue<pair<int,int> >temp;
	cin>>N;

	for(int i=0;i<N;i++){
		int S,T;
		cin>>S>>T;
		TS.push(make_pair(T,S));
	}

	pair<int,int>current=TS.top();

	while(!TS.empty()){
		pair<int,int>currnet=TS.top();
		TS.pop();
		if(TS.empty()){
			break;
		}

		while(1){
			pair<int,int>tmp=TS.top();
			TS.pop();
			
			while(current.first<){::
				
		
}
