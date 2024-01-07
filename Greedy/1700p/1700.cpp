#include <iostream>
#include <vector>

using namespace std;

int order[101];
int use_cnt[101];
int multi[101];
int N,K;

int main(void){
	cin>>N>>K;

	int use;
	for(int i=0;i<K;i++){
		cin>>order[i];
		use_cnt[order[i]]++;
	}

	//N
	int sol=0;
	for(int i=0;i<K;i++){
		for(int j=0;j<N;j++){
			if(multi[j]==0){
				multi[j]=order[i];
				use_cnt[oredr[i]]--;
				break;
			}
			else if(multi[j]!=0){
				int sindex=0;
				int scnt=1;
				for(int k=0;k<N;k++){
					
		}
	}
}
