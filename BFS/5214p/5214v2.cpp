#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int visited[100001];
int N,K,M;
vector<set<int> >v;

int bfs(){
        queue<int>q;
        q.push(1);
        visited[1]=1;

        while(!q.empty()){
                int current=q.front();
                q.pop();

                if(current==N){
                        return visited[current];
                }

                for(int next:v[current]){
                        if(!visited[next]){
                                q.push(next);
                                visited[next]=visited[current]+1;
                        }
                }
        }
        return -1;
}

int main(void){
        cin>>N>>K>>M;

        v.resize(N+1);

        for(int i=0;i<M;i++){
		set<int>temp;
                for(int j=0;j<K;j++){
                        int temps;
			cin>>temps;
			temp.insert(temps);
                }

                for(int node:temp){
                        for(int othernode:temp){
                                if(node!=othernode){
                                        v[node].insert(othernode);
                                }
                        }
                }
        }
        int sol=bfs();
        cout<<sol<<endl;
}
