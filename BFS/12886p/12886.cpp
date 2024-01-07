#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int visited[500][500][500];
int A,B,C;

int bfs(){
	queue<tuple<int,int,int> >q;
	q.push(make_tuple(A,B,C));
	visited[A][B][C]=1;

	while(!q.empty()){
		tuple<int,int,int>current=q.front();
		q.pop();
		int f=get<0>(current);
		int s=get<1>(current);
		int t=get<2>(current);
		if(get<0>(current)==get<1>(current)&&get<1>(current)==get<2>(current)){
			return 1;
		}

		if(f>s&&!visited[f-s][s+s][t]){
			q.push(make_tuple(f-s,s+s,t));
			visited[f-s][s+s][t]=1;
		}
		else if(f<s&&!visited[f+f][s-f][t]){
			q.push(make_tuple(f+f,s-f,t));
			visited[f+f][s-f][t]=1;
		}

		if(s>t&&!visited[f][s-t][t+t]){
			q.push(make_tuple(f,s-t,t+t));
			visited[f][s-t][t+t]=1;
		}
		else if(s<t&&!visited[f][s+s][t-s]){
			q.push(make_tuple(f,s+s,t-s));
			visited[f][s+s][t-s]=1;
		}

		if(s>f&&!visited[f+f][s-f][t]){
                        q.push(make_tuple(f+f,s-t,t));
                        visited[f+f][s-f][t]=1;
                }
                else if(s<f&&!visited[f-s][s+s][t]){
                        q.push(make_tuple(f-s,s+s,t));
                        visited[f-s][s+s][t]=1;
                }
	}
	return 0;
}

int main(void){
	cin>>A>>B>>C;
	int sol=bfs();
	cout<<sol<<endl;
}
