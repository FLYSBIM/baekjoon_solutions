#include <stdio.h>

char map[100][100];
int visited[100][100]={0};
int n;
int Bcount=0;
int Rcount=0;
int Gcount=0;

int DFS(int x,int y){
	if(x<0||x>=n||y<0||y>=n||visited[y][x]==1||map[y][x]=='R'||map[y][x]=='G'){
		return 0;
	}

	visited[y][x]=1;
	

	DFS(x,y+1);
	DFS(x,y-1);
	DFS(x+1,y);
	DFS(x-1,y);

	return 0;
}

int DFSR(int x,int y){
        if(x<0||x>=n||y<0||y>=n||visited[y][x]==1||map[y][x]=='B'||map[y][x]=='G'){
                return 0;
        }

        visited[y][x]=1;

        DFSR(x,y+1);
        DFSR(x,y-1);
        DFSR(x+1,y);
        DFSR(x-1,y);

        return 0;
}

int DFSG(int x,int y){
        if(x<0||x>=n||y<0||y>=n||visited[y][x]==1||map[y][x]=='R'||map[y][x]=='B'){
                return 0;
        }

        visited[y][x]=1;


        DFSG(x,y+1);
        DFSG(x,y-1);
        DFSG(x+1,y);
        DFSG(x-1,y);

        return 0;
}

int main(void){
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%s",map[i]);
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(visited[i][j]==0&&map[i][j]=='B'){
				DFS(j,i);
				Bcount++;
			}
			else if(visited[i][j]==0&&map[i][j]=='R'){
				DFSR(j,i);
				Rcount++;
			}
			else if(visited[i][j]==0&&map[i][j]=='G'){
				DFSG(j,i);
				Gcount++;
			}
		}		
	}
	int sol1=Bcount+Gcount+Rcount;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]=='G'){
				map[i][j]='R';
			}
			visited[i][j]=0;
		}
	}
	Bcount=0;
	Rcount=0;
	for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        if(visited[i][j]==0&&map[i][j]=='B'){
                                DFS(j,i);
                                Bcount++;
                        }
                        else if(visited[i][j]==0&&map[i][j]=='R'){
                                DFSR(j,i);
                                Rcount++;
                        }
                }
        }
	int sol2=Bcount+Rcount;
	printf("%d %d\n",sol1,sol2);
}
