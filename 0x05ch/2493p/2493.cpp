#include <iostream>
#include <stack>

using namespace std;

int main(void){
	stack<int>s;
	stack<int>s2;
	int n=0;
	int elem=0;
	cin>>n;

	int top[500001]={0};

	for(int i=0;i<n;i++){
		cin>>elem;
		s.push(elem);
	}
		
	s2.push(s.top());
	s.pop();

	while(s.empty()!=true){
		int index=n;

		if(s.top()<s2.top()){
			s2.push(s.top());
			n--;
			s.pop();
		}
		else if(s.top()>=s2.top(){
			top[n]=s.size();
			s2.pop();
		}

		if(s2.empty()==true){
                        s2.push(s.top());
			n--;
                        s.pop();
                }
	}






	for(int i=0;i<n;i++){
		cout<<s.top()<<" ";
		s.pop();
	}
}
