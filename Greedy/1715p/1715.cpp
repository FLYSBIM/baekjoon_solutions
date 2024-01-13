#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;

int main(void){
	cin>>N;
	
	if(N==1){
		cout<<0<<endl;
		return 0;
	}


	priority_queue<int,vector<int>,greater<int> >pq;
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		pq.push(a);
	}
	
	int sol=0;
	while(1){
		if(pq.size()==1){
			cout<<sol<<endl;
			return 0;
		}
	
		int c=pq.top();
		pq.pop();
		int d=pq.top();
		pq.pop();
		int e=c+d;
		pq.push(e);
		sol+=e;
	}
		

}
