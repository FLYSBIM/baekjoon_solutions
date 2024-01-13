#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void){
	int K;
	int T;
	cin>>T;

	while(T--){
		cin>>K;
		priority_queue<long long,vector<long long>,greater<long long> >pq;
		long long Si;
		for(int i=0;i<K;i++){
			cin>>Si;
			pq.push(Si);
		}
		long long sol=0;
		while(!pq.empty()){
			long long s1=pq.top();
			pq.pop();
			
			long long s2=pq.top();
			pq.pop();

			sol+=s1+s2;

			if(pq.empty()){
				cout<<sol<<endl;
			}
			else if(!pq.empty()){
				pq.push(s1+s2);
			}
		}
	}
}
			
