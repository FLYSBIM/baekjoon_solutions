#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int S[10];
char map[1000][1000];
int visited[1000][1000];
int N,M,P;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int terinum[10];
vector<queue<tuple<int,int,int> > >q(10);

int isval(int x,int y){
        return x>=0&&x<M&&y>=0&&y<N&&map[y][x]=='.'&&!visited[y][x];
}

int isedge(int x,int y){
        int toggle=0;
        if(isval(x+1,y)){
                return 1;
        }

        if(isval(x,y+1)){
                return 1;
        }

        if(isval(x-1,y)){
                return 1;
        }

        if(isval(x,y-1)){
                return 1;
        }

        return toggle;
}

int bfs(){
        for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                        if(isedge(j,i)&&map[i][j]>='1'&&map[i][j]<='9'){
                                q[map[i][j]-'0'].push(make_tuple(j,i,S[map[i][j]-'0']));
                                visited[i][j]=1;
                        }
                }
        }
	while(true){
		bool success=false;
        	for(int i=1;i<=P;i++){
			int s_len=S[i];
                	while(!q[i].empty()&&s_len--){
				int q_size=q[i].size();
				for(int j=0;j<q_size;j++){
                        	tuple<int,int,int>current=q[i].front();
                        	q[i].pop();

                       		for(int j=0;j<4;j++){
                                	int nx=dx[j]+get<0>(current);
                                	int ny=dy[j]+get<1>(current);

                                	if(isval(nx,ny)&&visited[get<1>(current)][get<0>(current)]){
                                        	visited[ny][nx]=visited[get<1>(current)][get<0>(current)]+1;
                                        	map[ny][nx]='0'+i;
                                        	q[i].push(make_tuple(nx,ny,get<2>(current)));
						success=true;
                                	}
                        	}
				}
                	}	
        	}
		if(!success)break;
	}
        return 1;
}
int main(void){
        cin>>N>>M>>P;
        for(int i=1;i<=P;i++){
                cin>>S[i];
        }

        for(int i=0;i<N;i++){
                cin>>map[i];
        }
        bfs();
        for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                        terinum[map[i][j]-'0']++;
                }
        }
        for(int i=1;i<=P;i++){
                cout<<terinum[i]<<" ";
        }
        cout<<endl;
}
