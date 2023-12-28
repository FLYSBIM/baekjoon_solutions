#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
	int N,M;
	cin>>N;
	vector<int>crain(N);	
	for(int i=0;i<N;i++){
		cin>>crain[i];
	}

	cin>>M;
	vector<int>box(M);	
	for(int i=0;i<M;i++){
		cin>>box[i];
	}

	sort(crain.rbegin(),crain.rend());
	sort(box.rbegin(),box.rend());
	
	if(crain.front()<box.front()){
		cout<<-1<<endl;
		return 0;
	}

	int time=0;
	
	while(!box.empty()){
		for(int& tempcrain:crain){
			if(tempcrain<box.back()){
				break;
			}			

			if(box.front()<=tempcrain){
				box.erase(box.begin());
				
			}
			else if(box.front()>tempcrain){
				int bindex=0;
				while(box[bindex]>tempcrain){
					bindex++;
					if(bindex==box.size()-1){
						break;
					}
				}
				box.erase(box.begin());
			}
		}
		time++;
	}
	cout<<time<<endl;	
}
