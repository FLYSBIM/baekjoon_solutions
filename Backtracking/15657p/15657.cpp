#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>visited;
vector<int>result;
vector<int>nums;
int N,M;

void backt(int k,int start){
	if(k==M){
		for(int i=0;i<k;i++){
			cout<<result[i]<<" ";
		}
		cout<<'\n';
		return ;
	}

	for(int i=start;i<N;i++){
		result[k]=nums[i];
		backt(k+1,i);
	}	
}

int main(void){
	cin>>N>>M;
	visited.resize(N);
	result.resize(M);
	nums.resize(N);
	
	for(int i=0;i<N;i++){
		cin>>nums[i];
	}
	
	sort(nums.begin(),nums.end());
		
	backt(0,0);
}
		
