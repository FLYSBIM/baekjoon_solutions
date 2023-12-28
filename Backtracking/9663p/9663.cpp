#include <iostream>
#include <vector>

using namespace std;

int N;
int sol=0;
int visited1[40];
int visited2[40];
int visited3[40];

void backt(int k){
	if(k==N){
		sol++;
		return ;
	}

	for(int i=0;i<N;i++){
		if(!visited1[i]&&!visited2[i+k]&&!visited3[k-i+N-1]){
			visited1[i]=1;
			visited2[i+k]=1;
			visited3[k-i+N-1]=1;
			backt(k+1);
			visited1[i]=0;
			visited2[i+k]=0;
			visited3[k-i+N-1]=0;
		}
	}	

}

int main(void){
	cin>>N;

	backt(0);
	cout<<sol<<endl;

}
