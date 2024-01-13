#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,K;

int main(void){
	cin>>N>>K;
	vector<int>baby(N);
	vector<int>dif(N-1);

	for(int i=0;i<N;i++){
		cin>>baby[i];
	}

	for(int i=0;i<N-1;i++){
		dif[i]=baby[i+1]-baby[i];
	}

	sort(dif.begin(),dif.end());

	int sol=0;

	for(int i=0;i<N-1-(K-1);i++){
		sol+=dif[i];
	}
	cout<<sol<<endl;
}
