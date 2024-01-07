#include <iostream>
#include <vector>

using namespace std;

int visited[100001];
int n;
int graph[100001];
int sol=0;
int pnum=0;

int dfs(int x,int start){
	visited[x]=1;
	pnum++;
	if(start==graph[x]){
		cout<<1<<endl;
		return 1;
	}

	if(!visited[graph[x]]){
		if(dfs(graph[x],start)){
			return pnum;
		}
	}
	return 0;
}

int main(void){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		int a=0;
		sol=0;
		for(int i=1;i<=n;i++){
			cin>>a;
			graph[i]=a;
			if(i==a){
				sol++;
				visited[i]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
                        	visited[j]=0;
                	}
			if(!visited[i]){
				pnum=0;
				int an=dfs(i,i);
				if(an!=0){
					sol+=an;
				}
			}
		}
		for(int i=1;i<=n;i++){
			visited[i]=0;
		}
		cout<<n-sol<<endl;
	}
}
