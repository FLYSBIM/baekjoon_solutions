#include <iostream>
#include <vector>

using namespace std;

struct Robot{
	int x;
	int y;
	int d;
};

vector<Robot>robot;
int map[101][101];
int A,B;
int N,M;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
//E=0,S=1,W=2,N=3

int isval(int x,int y){
	return x>0&&x<=A&&y>0&&y<=B;
}

int main(void){
	cin>>A>>B;
	cin>>N>>M;
	robot.resize(N+1);	

	for(int i=1;i<=N;i++){
		char dir;
		cin>>robot[i].x>>robot[i].y>>dir;
		if(dir=='E'){
			robot[i].d=0;
		}
		else if(dir=='S'){
			robot[i].d=1;
		}
		else if(dir=='W'){
			robot[i].d=2;
		}
		else if(dir=='N'){
			robot[i].d=3;
		}
		map[robot[i].y][robot[i].x]=i;
	}
	int t=0;
	int Case=0;
	int ro=0;
	while(M--){
		int num;
		char command;
		int cnt;
		cin>>num>>command>>cnt;

		if(command=='R'){
			while(cnt--){
				robot[num].d--;
				if(robot[num].d==-1){
					robot[num].d=3;
				}
			}
		}
		else if(command=='L'){
			while(cnt--){
				robot[num].d++;
				if(robot[num].d==4){
					robot[num].d=0;
				}
			}
		}
		else if(command=='F'){
			while(cnt--){
				map[robot[num].y][robot[num].x]=0;
				robot[num].x+=dx[robot[num].d];
				robot[num].y+=dy[robot[num].d];
				if(isval(robot[num].x,robot[num].y)&&t==0&map[robot[num].y][robot[num].x]!=0){
					t=num;
					Case=1;
					ro=map[robot[num].y][robot[num].x];
				}
				else if(isval(robot[num].x,robot[num].y)&&t==0&&robot[num].x<=0||robot[num].x>A||robot[num].y<=0&&robot[num].y>B){
					t=num;
					Case=2;
				}
				map[robot[num].y][robot[num].x]=num;
			}
		}
	}
	
	if(t==0){
		cout<<"OK"<<endl;
	}
	else if(t!=0){
		if(Case==1){
			cout<<"Robot "<<t<<" crashes into robot "<<ro<<endl;
		}
		else if(Case==2){
			cout<<"Robot "<<t<<" crashes into the wall"<<endl;
		}
	}
}
