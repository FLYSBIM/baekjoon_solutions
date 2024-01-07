#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int N,M;
vector<int>book;

int main(void){
	cin>>N>>M;
	book.resize(N);

	for(int i=0;i<N;i++){
		cin>>book[i];
	}

	sort(book.begin(),book.end());

	int sol=0;

	if(N==1){
		cout<<book[0]<<endl;
		return 0;
	}

	if(!book.empty()&&abs(book.front())<abs(book.back())){
		sol+=book.back();
		for(int i=0;i<M;i++){
			if(!book.empty()&&book.back()>0){
				book.pop_back();
			}
		}
	}
	else if(!book.empty()&&abs(book.front())>=abs(book.back())){
		sol+=abs(book.front());
		for(int i=0;i<M;i++){
			if(!book.empty()&&book.front()<0){
				book.erase(book.begin());
			}
		}
	}

	while(!book.empty()){
		int but=1;
		if(but&&book.front()>0){
			sort(book.rbegin(),book.rend());
			but=0;
		}

		if(book.front()<0){
			sol+=2*abs(book.front());
			for(int i=0;i<M;i++){
				if(!book.empty()&&book.front()<0){
					book.erase(book.begin());
				}
			}
		}
		else if(book.front()>0){
			sol+=2*book.front();
			for(int i=0;i<M;i++){
				if(!book.empty()&&book.front()>0){
					book.erase(book.begin());
				}
			}
		}
	}
	cout<<sol<<endl;
}
