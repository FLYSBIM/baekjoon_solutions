/*#include <stdio.h>

char map[100][100];
int visited[100][100]={0};
int N,M;

int dfsB(int x,int y){
	if(x<0 || x>=N || y<0 || y>=M || visited[y][x]==1 || map[y][x]=='W'){
		return 0;
	}
	
	visited[y][x]=1;	
	
	int area=1;
	
	area+=dfsB(x,y+1);
	area+=dfsB(x,y-1);
	area+=dfsB(x+1,y);
	area+=dfsB(x-1,y);
	
	return area;
}

int dfsW(int x,int y){
        if(x<0||x>=N||y<0||y>=M||visited[y][x]==1||map[y][x]=='B'){
                return 0;
        }

	visited[y][x]=1;

        int area=1;

        area+=dfsW(x,y+1);
        area+=dfsW(x,y-1);
        area+=dfsW(x+1,y);
        area+=dfsW(x-1,y);

        return area;
}

int main(void){
	scanf("%d%d",&N,&M);

	for(int i=0;i<M;i++){
		scanf("%s",map[i]);
	}

	int Bpower=0;
	int Wpower=0;
	int BB,WW;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			if(map[i][j]=='B'&&visited[i][j]==0){
				BB=dfsB(j,i);
				Bpower=Bpower+(BB*BB);
			}
			else if(map[i][j]=='W'&&visited[i][j]==0){
				WW=dfsW(j,i);
				Wpower=Wpower+(WW*WW);
			}
		}
	}
	
	printf("%d %d\n",Wpower,Bpower);
}*/
#include <stdio.h>

char map[100][100];
int visited[100][100] = {0};
int N, M;

int dfs(int x, int y, char team) {
    if (x < 0 || x >= N || y < 0 || y >= M || visited[y][x] == 1 || map[y][x] != team) {
        return 0;
    }

    visited[y][x] = 1;

    int area = 1;

    area += dfs(x, y + 1, team);
    area += dfs(x, y - 1, team);
    area += dfs(x + 1, y, team);
    area += dfs(x - 1, y, team);

    return area;
}

int main(void) {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++) {
        scanf("%s", map[i]);
    }

    int B_power = 0;
    int W_power = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 'B' && visited[i][j] == 0) {
		int BB=dfs(j,i,'B');
                B_power += (BB*BB);
            } else if (map[i][j] == 'W' && visited[i][j] == 0) {
		int WW=dfs(j,i,'W');
                W_power += (WW*WW);
            }
        }
    }

    printf("%d %d\n", B_power, W_power);

    return 0;
}

