#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int map[100][100];
int visited[100][100][10000];
int N,M,T;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int bfs(){
        queue<tuple<int,int,int,int> >q;
        //x,y,Issword,wallnum
        if(map[0][0]==2){
                q.push(make_tuple(0,0,1,0));
        }
	else if(map[0][0]==0){
		q.push(make_tuple(0,0,0,0));
	}
	visited[0][0][0]=1;
        while(!q.empty()){
                tuple<int,int,int,int>current=q.front();
                q.pop();

                if(get<0>(current)==M-1&&get<1>(current)==N-1){
                        return visited[get<1>(current)][get<0>(current)][get<3>(current)]-1;
                }

                for(int i=0;i<4;i++){
                       	int nx=dx[i]+get<0>(current);
                       	int ny=dy[i]+get<1>(current);

                        if(nx>=0&&nx<M&&ny>=0&&ny<N&&!visited[ny][nx][get<3>(current)]){
                               	if(map[ny][nx]==0){
                               	        q.push(make_tuple(nx,ny,get<2>(current),get<3>(current)));
                               	}
                             	else if(map[ny][nx]==2){
                                      	q.push(make_tuple(nx,ny,1,get<3>(current)));
                               	}	
                               	visited[ny][nx][get<3>(current)]=visited[get<1>(current)][get<0>(current)][get<3>(current)]+1;
                       	}
               	}
                
                if(get<2>(current)==1){
                        for(int i=0;i<4;i++){
                                int nx=dx[i]+get<0>(current);
                                int ny=dy[i]+get<1>(current);

                                if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[ny][nx]==1&&!visited[ny][nx][get<3>(current)+1]){
                                        visited[ny][nx][get<3>(current)+1]=visited[get<1>(current)][get<0>(current)][get<3>(current)]+1;
                                        q.push(make_tuple(nx,ny,1,get<3>(current)+1));
                                }
                        }
                }
		cout<<"y"<<get<1>(current)<<"x"<<get<0>(current)<<visited[get<1>(current)][get<0>(current)][get<3>(current)]-1<<endl;
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
