#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int map[50][50];
int visited[50][50];
int N,M;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int isrow(int x,int y){
        for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[ny][nx]>=map[y][x]){
                        return 1;
                }
        }
        return 0;
}

void initvisit(){
        for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                        visited[i][j]=0;
                }
        }
}

int bfs(int x,int y){
        initvisit();
        queue<pair<int,int> >q2;
        q2.push(make_pair(x,y));
        visited[y][x]=1;
        int area=1;
        int toggle=0;
        int min_height=10001;
        int now_height=map[y][x];
        vector<pair<int,int> >a;
        a.push_back(make_pair(x,y));
        int atoggle=-1;
        while(!q2.empty()){
                pair<int,int>current=q2.front();
                q2.pop();
                int cx=current.first;
                int cy=current.second;
                for(int i=0;i<4;i++){
                        int nx=cx+dx[i];
                        int ny=cy+dy[i];

                        if(nx>=0&&nx<M&&ny>=0&&ny<N&&!visited[ny][nx]){
                                if(map[ny][nx]>map[cy][cx]){
                                        min_height=min(min_height,map[ny][nx]);
                                        visited[ny][nx]=1;
                                }
                                else if(map[ny][nx]==map[cy][cx]){
                                        if(ny==0||nx==0||ny==N-1||nx==M-1){
                                                toggle=1;
                                        }
                                        a.push_back(make_pair(nx,ny));
                                        visited[ny][nx]=1;
                                        area++;
                                        q2.push(make_pair(nx,ny));
                                }
                                else if(map[ny][nx]<map[cy][cx]){
                                        toggle=1;
                                }
                        }
                }
                if(toggle){
                        break;
                }
        }
        if(toggle){
                area=0;
        }
        else if(!toggle){
                for(int i=0;i<a.size();i++){
                        map[a[i].second][a[i].first]=min_height;
                }
                atoggle=0;
        }
        if(atoggle==-1){
                return -1;
        }
        return area*(min_height-now_height);
}

int main(void){
        cin>>N>>M;

        for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
			char a;
			cin>>a;
                        map[i][j]=a-'0';
                }
        }
        int sol=0;
        while(1){
                int toggle=1;
                vector<pair<int,int> >v1;
                for(int i=1;i<N-1;i++){
                        for(int j=1;j<M-1;j++){
                                if(isrow(j,i)){
                                        v1.push_back(make_pair(j,i));
                                        toggle=0;
                                }
                        }
                }
                int ck=0;
                for(int i=0;i<v1.size();i++){
                        int water=bfs(v1[i].first,v1[i].second);
                        if(water!=-1){
                                sol+=water;
                        }

                        ck+=water;
                        if(ck==-1*v1.size()){
                                toggle=1;
                        }
                }

                if(toggle){
                        break;
                }
        }
        cout<<sol<<endl;
}
