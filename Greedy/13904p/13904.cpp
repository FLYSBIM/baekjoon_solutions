#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main(void){
	int sol=0;
	priority_queue<pair<int,int> > dw;
	priority_queue<pair<int,int> > wd;
	cin>>N;

	int d,w;
	int day=0;
	for(int i=0;i<N;i++){
		cin>>d>>w;
		dw.push(make_pair(d,w));
		day=max(day,d);
	}

	for(int i=day;i>=1;i--){
		while(1){
			pair<int,int>current=dw.top();
			int cd=current.first;
			int cw=current.second;
			
			if(dw.empty()||i>cd){
				break;
			}
			else if(!dw.empty()&&i<=cd){
				wd.push(make_pair(cw,cd));
				dw.pop();
			}
		}
		
		if(!wd.empty()){
			pair<int,int>current=wd.top();
			wd.pop();
			sol+=current.first;
		}
	}
	cout<<sol<<endl;
}
