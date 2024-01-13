#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int N,S;
	cin>>N;
	vector<int>v(N);
		
	for(int i=0;i<N;i++){
		cin>>v[i];
	}

	cin>>S;

	while(S--){
		int toggle=1;
		for(int i=0;i<N-1;i++){
			if(v[i]<v[i+1]){
				int tmp=v[i];
				v[i]=v[i+1];
				v[i+1]=tmp;
				toggle=0;
				break;
			}
		}
		if(toggle){
			break;
		}
	}
	
	for(int i=0;i<N;i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}
