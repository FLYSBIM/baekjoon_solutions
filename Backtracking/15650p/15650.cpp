#include <iostream>

using namespace std;

int visited[8];
int N,M;
vector<int>sq(8);

void backt(int k){
	if(k==M){
		for(int i=0;i<M;i++){
			cout<<sq[i]<<" ";
		}
		cout<<endl;
		return ;
	}

	for(int i=1;i<=N;i++){
		if(!visited[i]){
			if(k>0&&i<sq[k-1]){
				continue;
			}
			visited[i]=1;
			sq[k]=i;
			backt(k+1);
			visited[i]=0;
		}
	}
}

int main(void){
	cin>>N>>M;

	backt(0);
}
		
