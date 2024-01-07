#include <iostream>
#include <vector>

using namespace std;

int map[50][50];
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int N,M,r,c,d;

int isdirty(int x,int y){
	for(int i=0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[ny][nx]==0){
			return 1;
		}
	}
	return 0;
}

int main(void){
	cin>>N>>M;
	cin>>r>>c>>d;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>map[i][j];
		}
	}

	int sol=0;	
	int currentx=c;
	int currenty=r;
	int direc=d;
	int toggle=0;
	while(1){
		cout<<"currenty: "<<currenty<<"currentx: "<<currentx<<"d: "<<d<<endl;
		if(map[currenty][currentx]==0){
			map[currenty][currentx]=2;
			sol++;
		}

		if(isdirty(currentx,currenty)){
			d--;
			if(d==-1){
				d=3;
			}
			
			int nx=currentx+dx[d];
			int ny=currenty+dy[d];
			if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[ny][nx]==0){
				currentx=nx;
				currenty=ny;
			}
		}
		else{
			int nx=currentx-dx[d];
			int ny=currenty-dy[d];
			if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[ny][nx]!=1){
				currentx=nx;
				currenty=ny;
			}
			else if(nx>=0&&nx<M&&ny>=0&&ny<N&&map[ny][nx]==1){
				toggle=1;
			}
		}
		if(toggle){
			break;
		}
        }
	cout<<sol<<endl;
}
