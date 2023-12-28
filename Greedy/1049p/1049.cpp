#include <iostream>

using namespace std;

int main(void){
	int N,M;
	int price[50][2];
	cin>>N>>M;
	
	for(int i=0;i<M;i++){
		cin>>price[i][0]>>price[i][1];
	}

	int sol=0;

	int pack_cheap=price[0][0];
	int one_cheap=price[0][1];

	for(int i=1;i<M;i++){
		pack_cheap=min(pack_cheap,price[i][0]);
		one_cheap=min(one_cheap,price[i][1]);
	}

	if(one_cheap*6<pack_cheap){
		cout<<N*one_cheap<<endl;
		return 0;
	}

	if(N>=6){
		sol+=N/6*pack_cheap;
		N%=6;
		if(pack_cheap<N*one_cheap){
			sol+=pack_cheap;
		}
		else{
			sol+=one_cheap*N;
		}
	}
	else if(N<6){
		if(pack_cheap<N*one_cheap){
                        sol+=pack_cheap;
                }
                else{
                        sol+=one_cheap*N;
                }
	}
	cout<<sol<<endl;
}
	
	
