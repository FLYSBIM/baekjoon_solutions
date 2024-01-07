#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int map[21][21];
int visited[21][21];
int N,M,E;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
pair<int,int>taxi;
int nowcusnum;
vector<
void initvisit();

struct Compare {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if (a.second != b.second) {
            return a.second < b.second;
        } else {
            return a.first < b.first;
        }
    }
};

int isval(int x,int y){
	return x>0&&x<=N&&y>0&&y<=N;
}


int finddestination(){
	initvisit();
	queue<pair<int,int> >q;
	q.push(taxi);
	visited[taxi.second][taxi.first]=1;
	while(!q.empty()){
		pair<int,int>current=q.front();
		q.pop();
		
		for(int i=0;i<4;i++){
			int nx=dx[i]+current.first;
			int ny=dy[i]+current.second;
			
			if(isval(nx,ny)&&map[ny][nx]!=1&&!visited[ny][nx]){
				if(map[ny][nx]==nowcusnum+1){
					map[ny][nx]=0;
					taxi.first=nx;
					taxi.second=ny;
					return visited[current.second][current.first];
				}
				else{
					q.push(make_pair(nx,ny));
					visited[ny][nx]=visited[current.second][current.first]+1;
				}
			}
		}
	}
	return 0;
}

int findcustomer(){
	initvisit();
	priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> pq;
	pq.push(taxi);
	visited[taxi.second][taxi.first]=1;

	while(!pq.empty()){
	}	
	return 0;
}	

void initvisit(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			visited[i][j]=0;
		}
	}
} 

int main(void){
	cin>>N>>M>>E;
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin>>map[i][j];
		}
	}

	int taxi_x,taxi_y;
	cin>>taxi_y>>taxi_x;
	taxi.first=taxi_x;
	taxi.second=taxi_y;

	int cx,cy,dex,dey;
	for(int i=4;i<2*M+4;i+=2){
		cin>>cy>>cx>>dey>>dex;
		map[cy][cx]=i;
		map[dey][dex]=i+1;
	}
	int sol=E;
	
	int button=-1;
	while(1){
		int findener=findcustomer();
		E-=findener;
		if(findener==0||E<=0){
			button=1;
			break;
		}
		int finddes=finddestination();
		E-=finddes;
		if(finddes==0||E<0){
			button=1;
			break;
		}
		E+=2*finddes;
		cout<<"onect"<<E<<endl;
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				cout<<map[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(map[i][j]!=0&&map[i][j]!=1){
				cout<<-1<<endl;
				return 0;
			}
		}
	}

	if(E<0){
		cout<<-1<<endl;
	}
	else{
		cout<<E<<endl;
	}

/*
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;*/
}	
