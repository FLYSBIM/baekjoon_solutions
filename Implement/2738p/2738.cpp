#include <iostream>

using namespace std;

int main(void){

	int a,b;
	
	int mat1[100][100];
	int mat2[100][100];
	
	cin>>a>>b;

	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			cin>>mat1[i][j];
		}
	}
	
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			cin>>mat2[i][j];
		}
	}
	
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			mat1[i][j]+=mat2[i][j];
		}
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			cout<<mat1[i][j]<<" ";
		}
		cout<<endl;
	}
}
