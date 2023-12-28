#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int A,B,C;
int visited[201][201][201];

int dfs(){
	visited[A][B][C]=1;

	if(C>A){
		
}

int main(void){
	cin>>A>>B>>C;

	bfs();

	int sol=0;
	for(int i=0;i<=B;i++){
		for(int j=0;j<=C;j++){
			if(visited[0][i][j]==1){
				cout<<j<<" ";
			}
		}
	}
	cout<<endl;
}
			
