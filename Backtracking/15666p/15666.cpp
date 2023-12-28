#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;
vector<int>nums;
vector<int>result;
vector<int>used;

void backt(int k,int up){
	if(k==M){
		for(int i=0;i<M;i++){
			cout<<result[i]<<" ";
		}
		cout<<endl;
		return ;
	}
	int prev_num=-1;
	for(int i=0;i<N;i++){
		if(up<=nums[i]&&prev_num!=nums[i]){
			result[k]=nums[i];
			prev_num=nums[i];
			backt(k+1,nums[i]);
			result[k]=0;
		}
	}

}

int main(void){
	cin>>N>>M;
	nums.resize(N);
	result.resize(M);
	used.resize(N);

	for(int i=0;i<N;i++){
		cin>>nums[i];
	}	
	sort(nums.begin(),nums.end());

	backt(0,0);
}
