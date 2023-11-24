#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void){
	int N=0;
	cin>>N;

	stack<int>s;

	string command="aa";
	for(int i=0;i<N;i++){
		cin>>command;
		
		if(command=="push"){
			int putele=0;
			cin>>putele;
			s.push(putele);
		}
		else if(command=="top"){
			if(!s.empty()){
				cout<<s.top()<<endl;
			}
			else{
				cout<<-1<<endl;
			}
		}
		else if(command=="size"){
			cout<<s.size()<<endl;
		}
		else if(command=="pop"){
			if(!s.empty()){
				cout<<s.top()<<endl;
				s.pop();
			}
			else{
				cout<<-1<<endl;
			}
		}
		else if(command=="empty"){
			if(s.empty()){
				cout<<1<<endl;
			}
			else{
				cout<<0<<endl;
			}
		}
	}
}
