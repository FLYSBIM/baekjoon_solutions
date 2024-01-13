#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

priority_queue<pair<long,long> >pq;
//V,M;
int N,K;
vector<long>bag;

struct Compare {
    bool operator()(const pair<long, long>& a, const pair<long, long>& b) {
        if (a.first != b.first) {
            return a.first <  b.first;
        }
        return a.second <  b.second;
    }
};

int main(void){
	cin>>N>>K;

	priority_queue<pair<long,long>,vector<pair<long,long> >,Compare >pq;
	bag.resize(K);

	for(int i=0;i<N;i++){
		long M,V;
		cin>>M>>V;
		pq.push(make_pair(V,M));
	}

	for(int i=0;i<K;i++){
		cin>>bag[i];
	}

	sort(bag.begin(),bag.end());

	long sol=0;
	while(!bag.empty()&&!pq.empty()){
		pair<long,long>jw=pq.top();
		pq.pop();


		vector<long>::iterator it=lower_bound(bag.begin(),bag.end(),jw.second);

		if(it!=bag.end()){
			sol+=jw.first;
			bag.erase(it);
		}
	}
	cout<<sol<<endl;		
}
