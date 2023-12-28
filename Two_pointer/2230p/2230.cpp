#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int N,M;
	cin>>N>>M;
	vector<int>arr(N);

	for(int i=0;i<N;i++){
		cin>>arr[i];
	}

	sort(arr.begin(),arr.end());

	int left_pointer=0;
	int right_pointer=arr.size()-1;
	
	int sol=1000000000;
	int but=1;
	while(but==1&&left_pointer<=right_pointer&&arr[right_pointer]-arr[left_pointer]>=M){
		cout<<"a-b"<<arr[right_pointer]-arr[left_pointer]<<endl;
		but=0;
		if(arr[right_pointer-1]-arr[left_pointer]<arr[right_pointer]-arr[left_pointer+1]){
			if(arr[right_pointer-1]-arr[left_pointer]>=M){
				right_pointer--;
				but=1;
			}
			else if(arr[right_pointer]-arr[left_pointer+1]>=M){
                                left_pointer++;
				but=1;
                        }
		}
		else{
			if(arr[right_pointer]-arr[left_pointer+1]>=M){
				left_pointer++;
				but=1;
			}
			else if(arr[right_pointer-1]-arr[left_pointer]>=M){
                                right_pointer--;
				but=1;
                        }
		}

		if(arr[right_pointer]-arr[left_pointer]>=M){
			sol=min(sol,arr[right_pointer]-arr[left_pointer]);
		}
	}
	cout<<sol<<endl;
}
