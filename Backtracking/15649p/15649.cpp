#include <iostream>
#include <vector>

int visited[100]={0};

int dfs(int x){
	visited[x]=1;
	cout<<x<<" ";
	for(int i=1;i<=4;i++){
		if(visited[i]!=1){
			dfs(i);
		}
		visited[x]=0;
	}
	return 0;
}

