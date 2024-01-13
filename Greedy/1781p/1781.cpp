#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

int main(void){
	cin>>N;

	int day=0;
	priority_queue<pair<int,int> >dc;
	priority_queue<pair<int,int> >cd;

	for(int i=0;i<N;i++){
		int d,c;
		cin>>d>>c;
		dc.push(make_pair(d,c));
		day=max(day,d);
	}
	
	int sol=0;
	for(int i=day;i>=1;i--){
		while(1){
			pair<int,int>current=dc.top();
			int cday=current.first;
			int ccup=current.second;	
			if(dc.empty()||cday<i){
				break;
			}
			else if(!dc.empty()&&cday>=i){
				cd.push(make_pair(ccup,cday));
				dc.pop();
			}
		}

		if(!cd.empty()){
			pair<int,int>current=cd.top();
			sol+=current.first;
			cd.pop();
		}
	}
	cout<<sol<<endl;
}
