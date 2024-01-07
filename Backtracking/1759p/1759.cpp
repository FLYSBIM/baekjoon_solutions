#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L,C;
char str[15];
vector<char>al;
int aeiou=0;
int ja=0;

void backt(int k,int idx){
	if(k==L){
		if(aeiou>=1&&ja>=2){
			for(int i=0;i<L;i++){
				cout<<str[i];
			}
			cout<<endl;
		}
		return ;
	}

	for(int i=idx;i<C;i++){
		if(al[i]=='a'||al[i]=='e'||al[i]=='i'||al[i]=='o'||al[i]=='u'){
			aeiou++;
		}
		else{
			ja++;
		}
		str[k]=al[i];
		backt(k+1,i+1);
		if(al[i]=='a'||al[i]=='e'||al[i]=='i'||al[i]=='o'||al[i]=='u'){
                        aeiou--;
                }
                else{
                        ja--;
                }
		str[k]='\0';
	}
		
}

int main(void){
	cin>>L>>C;

	al.resize(C);

	for(int i=0;i<C;i++){
		cin>>al[i];
	}
	
	sort(al.begin(),al.end());

	backt(0,0);
}
