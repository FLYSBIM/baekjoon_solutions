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
		vector<int>&tempcrain=crain;
		int tsize=tempcrain.size();
		for(int i=0;i<tsize;i++){
			if(tempcrain[i]<box.back()){
				break;
			}			

			if(box.front()<=tempcrain[i]&&!box.empty()){
				box.erase(box.begin());
				
			}
			else if(box.front()>tempcrain[i]){
				int bindex=0;
				while(bindex<box.size()&&box[bindex]>tempcrain[i]){
					bindex++;
				}
				if(bindex<box.size()&&!box.empty()){
					box.erase(box.begin()+bindex);
				}
			}
		}
		time++;
	}
	cout<<time<<endl;	
}
