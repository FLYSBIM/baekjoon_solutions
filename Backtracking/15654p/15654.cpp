#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,M;
int visited[10];
vector<int>result;
vector<int>nums;
void backtracking(int k){
	if(k==M){
		for(int i=0;i<k;i++){
			cout<<result[i]<<" ";
		}
		cout<<endl;
		return ;
	}
	
	for(int i=0;i<N;i++){
		if(!visited[i]){
			visited[i]=1;
			result[k]=nums[i];
			backtracking(k+1);
			visited[i]=0;
		}
	}
}


int main(void){
	cin>>N>>M;
	
	nums.resize(N);
	result.resize(M);
	for(int i=0;i<N;i++){
		cin>>nums[i];
	}
	sort(nums.begin(),nums.end());

	backtracking(0);
}
