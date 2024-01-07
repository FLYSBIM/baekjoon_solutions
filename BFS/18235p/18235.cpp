#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int visited1[500001];
int visited2[500001];
int N,A,B;
queue<int>five;
queue<int>six;
int jump=1;
int cnt=2;
int bfs(){
	while(!five.empty()&&!six.empty()){
		int Fsize=five.size();
		for(int i=0;i<Fsize;i++){
			int current=five.front();
			five.pop();

			if(visited1[current]==visited2[current]){
                                return visited1[current]-1;
                        }

                        if(current+jump<=N){
                                visited1[current+jump]=cnt;
                                five.push(current+jump);
                        }

                        if(current-jump>0){
                                visited1[current-jump]=cnt;
                                five.push(current-jump);
                        }
		}
		int Ssize=six.size();
		for(int i=0;i<Ssize;i++){
			int current=six.front();
			six.pop();
					
			if(visited1[current]==visited2[current]){
				return visited1[current]-1;
			}

			if(current+jump<=N){
				visited2[current+jump]=cnt;
				six.push(current+jump);
			}
			
			if(current-jump>0){
				visited2[current-jump]=cnt;
				six.push(current-jump);
			}
		}
		jump*=2;
		cnt++;
	}
	return -1;
}

int main(void){
	cin>>N>>A>>B;
	five.push(A);
	visited1[A]=1;
	six.push(B);
	visited2[B]=1;
	int sol=bfs();
	cout<<sol<<endl;
}
