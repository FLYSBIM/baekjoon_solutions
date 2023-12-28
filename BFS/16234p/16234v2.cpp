#include <iostream>
#include <tuple>
#include <queue>
#include <cstdlib>

using namespace std;

int map[50][50];
int visited[50][50];
int N,L,R;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int pou[2501][2];

int isval(int a,int b){
        return a>=0&&a<N&&b>=0&&b<N&&!visited[b][a];
}//V

int dif(int x1,int y1,int x2,int y2){
        return abs(map[y1][x1]-map[y2][x2])<=R&&abs(map[y1][x1]-map[y2][x2])>=L;
}//V

int bfs(){
        queue<tuple<int,int,int> >q;
        int but=0;
        int comnum=1;
        for(int j=0;j<N;j++){
                for(int k=0;k<N;k++){
                        if(!visited[j][k]){
                                q.push(make_tuple(k,j,comnum));
                                visited[j][k]=comnum;
                                while(!q.empty()){
                                        tuple<int,int,int>current=q.front();
                                        q.pop();
                                        for(int i=0;i<4;i++){
                                                int nx=dx[i]+get<0>(current);
                                                int ny=dy[i]+get<1>(current);

                                                if(isval(nx,ny)&&dif(nx,ny,get<0>(current),get<1>(current))){
                                                        q.push(make_tuple(nx,ny,get<2>(current)));
                                                        visited[ny][nx]=get<2>(current);
                                                        but=1;
                                                }
                                        }
                                }
                                comnum++;
                        }
                }
        }
        for(int i=0;i<N;i++){
               	for(int j=0;j<N;j++){
			pou[visited[i][j]][0]+=map[i][j];
                        pou[visited[i][j]][1]++;
                }
        }
	for(int i=1;i<=comnum;i++){
		if(pou[i][1]!=0){
			pou[i][0]/=pou[i][1];
		}
	}
        for(int i=0;i<N;i++){
    	        for(int j=0;j<N;j++){
                        map[i][j]=pou[visited[i][j]][0];
                        visited[i][j]=0;//g   
                }
        }
	for(int i=0;i<=comnum;i++){
		pou[i][0]=0;
		pou[i][1]=0;
	}
        if(but==1){
            return 1;
        }
        return 0;
}

int main(void){
        cin>>N>>L>>R;

        for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                        cin>>map[i][j];
                }
        }
        int i=0;
 
        while(1){
                int sol=bfs();
                if(sol==0){
                    cout<<i<<endl;
                    return 0;
                }
                i++;
        }
}
