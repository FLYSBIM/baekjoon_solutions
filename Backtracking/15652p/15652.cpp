#include <iostream>
#include <vector>

using namespace std;

int N,M;
int visited[9];
vector<int>sq(8);

void backt(int k,int start){
	if(k==M){
		for(int i=0;i<k;i++){
			cout<<sq[i]<<" ";
		}
		cout<<endl;
		return ;
	}

	for(int i=start;i<=N;i++){
		sq[k]=i;
		backt(k+1,i);
	}
}

int main(void){
	cin>>N>>M;
	
	backt(0,1);
}

			
