#include <iostream>
#include <cstring>

using namespace std;

int main(void){
	char arr[1000001];
	
	cin>>arr;
	int alp[26]={0};

	for(int i=0;i<strlen(arr);i++){
		if(arr[i]>='a'&&arr[i]<='z'){
			alp[arr[i]-'a']++;
		}
		else if(arr[i]>='A'&&arr[i]<='Z'){
			alp[arr[i]-'A']++;
		}
	}
	int Max=-1;
	int maxindex=0;
	for(int i=0;i<26;i++){
		if(Max<alp[i]){
			maxindex=i;
			Max=max(Max,alp[i]);
		}
		else if(Max==alp[i]){
			cout<<"?"<<endl;
			return 0;
		}
	}
	cout<<(char)(maxindex+'A')<<endl;
}	
		
