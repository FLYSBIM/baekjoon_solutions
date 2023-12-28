#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int map[100][100];
int visited[100][100][8000];
int N,M,T;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int bfs(){
        queue<tuple<int,int,int,int> >q;
        q.push(make_tuple(0,0,0,0));
        //x,y,wall,sword,time
        visited[0][0][0]=1;
        if(map[0][0]==2){
                q.pop();
                q.push(make_tuple(0,0,0,1));
        }
        while(!q.empty()){
                tuple<int,int,int,int>current=q.front();
                q.pop();

                if(get<0>(current)==M-1&&get<1>(current)==N-1){
                        return visited[get<1>(current)][get<0>(current)][get<2>(current)]-1;
                }

                if(get<3>(current)==0){
                        for(int i=0;i<4;i++){
                                int nx=dx[i]+get<0>(current);
                                int ny=dy[i]+get<1>(current);

                                if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[ny][nx]!=1&&!visited[ny][nx][get<2>(current)]){
                                        if(map[ny][nx]==0){
                                                q.push(make_tuple(nx,ny,get<2>(current),get<3>(current)));
                                        }
                                        else if(map[ny][nx]==2){
                                                q.push(make_tuple(nx,ny,get<2>(current),1));
                                        }
                                        visited[ny][nx][get<2>(current)]=visited[get<1>(current)][get<0>(current)][get<2>(current)]+1;
                                }
                        }
                }
                else if(get<3>(current)==1){
                        for(int i=0;i<4;i++){
                                int nx=dx[i]+get<0>(current);
                                int ny=dy[i]+get<1>(current);

                                if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[ny][nx]==1&&!visited[ny][nx][get<2>(current)+1]){
                                        visited[ny][nx][get<2>(current)+1]=visited[get<1>(current)][get<0>(current)][get<2>(current)]+1;
                                        q.push(make_tuple(nx,ny,get<2>(current)+1,1));
                                }
                                else if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[ny][nx]==0&&!visited[ny][nx][get<2>(current)]){
                                        visited[ny][nx][get<2>(current)]=visited[get<1>(current)][get<0>(current)][get<2>(current)]+1;
                                        q.push(make_tuple(nx,ny,get<2>(current),1));
                                }
                        }
                }
        }
        return -1;
}

int main(void){
        cin>>N>>M>>T;

        for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                        cin>>map[i][j];
                }
        }

        int sol=bfs();
        if(sol==-1){
                cout<<"Fail"<<endl;
        }
        else{
                cout<<sol<<endl;
        }
}
