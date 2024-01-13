#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;

int main(void){
	cin>>n;

	priority_queue<pair<int,int> >pd;
	priority_queue<pair<int,int> >pq;
	int day=0;

	for(int i=0;i<n;i++){
		int p,d;
		cin>>p>>d;
		pq.push(make_pair(d,p));
		day=max(day,d);
	}
	int sol=0;
	for(int i=day;i>=1;i--){
		while(1){
			pair<int,int>current=pq.top();

			if(pq.empty()||i>current.first){
				break;
			}
			else if(!pq.empty()&&i<=current.first){	
				pq.pop();
				pd.push(make_pair(current.second,current.first));
			}
		}
		if(!pd.empty()){
			pair<int,int>current=pd.top();
			pd.pop();
			sol+=current.first;
		}	
	}		
	cout<<sol<<endl;
}
