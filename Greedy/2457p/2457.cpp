#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
	int N;
	cin>>N;
	vector<pair<pair<int,int>,pair<int,int> > >v;
	vector<pair<int,int> >v2;

	for(int i=0;i<N;i++){
		int sm,sd,em,ed;
		cin>>sm>>sd>>em>>ed;
		if(sm<3||sm==3&&sd==1){
			v2.push_back(make_pair(em,ed));
		}
		else{
			v.push_back(make_pair(make_pair(sm,sd),make_pair(em,ed)));
		}
	}
	//end
	sort(v2.begin(),v2.end());
	sort(v.rbegin(),v.rend());
	
	pair<int,int>current=v2.back();
	int sol=1;
	while(1){
		vector<pair<int,int> >tmp;
		if(current.first>11){
			break;
		}

		while(!v.empty()){
			pair<pair<int,int>,pair<int,int> >flower=v.back();
			int fsm=flower.first.first;
			int fsd=flower.first.second;
			if(fsm<current.first||fsm==current.first&&fsd<=current.second){
				tmp.push_back(make_pair(flower.second.first,flower.second.second));
				v.pop_back();
			}
			else{
				break;
			}
		}
		if(!tmp.empty()){
			sort(tmp.begin(),tmp.end());
			current=tmp.back();
			tmp.pop_back();
			sol++;
		}
		else if(tmp.empty()){
			cout<<0<<endl;
			return 0;
		}
	}
	cout<<sol<<endl;
}
