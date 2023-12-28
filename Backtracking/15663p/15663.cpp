#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int>result;
vector<int>nums;
vector<int>visited;

void backt(int k){
	if(k==M){
		for(int i=0;i<k;i++){
			cout<<result[i]<<" ";
		}
		cout<<'\n';
		return ;
	}

	int prev_num=-1;

	for(int i=0;i<N;i++){
		if(!visited[i]&&prev_num!=nums[i]){
			visited[i]=1;
			prev_num=nums[i];
			result[k]=nums[i];
			backt(k+1);
			visited[i]=0;
		}
	}	
}

int main(void){
	cin>>N>>M;

	result.resize(M);
	nums.resize(N);
	visited.resize(N);

	for(int i=0;i<N;i++){
		cin>>nums[i];
	}
	
	sort(nums.begin(),nums.end());

	backt(0);
}
