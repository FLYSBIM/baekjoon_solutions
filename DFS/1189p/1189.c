#include <stdio.h>

char map[5][5];
int visited[5][5]={0};
int R,C,K;
int count=0;
int dfs(int x,int y,int K){
	
	if(x==C-1&&y==0){
		if(K==1){
			count++;
		}
		return 0;
	}

	visited[y][x]=1;
	
int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 유효한 범위 내에 있고, 방문하지 않은 곳이면 재귀적으로 탐색
        if (nx >= 0 && nx < C && ny >= 0 && ny < R && !visited[ny][nx] && map[ny][nx] != 'T') {
            dfs(nx, ny, K- 1);
        }
    }
	visited[y][x]=0;

	return 0;
}

int main(void){
	scanf("%d%d%d",&R,&C,&K);

	for(int i=0;i<R;i++){
		scanf("%s",map[i]);
	}

	dfs(0,R-1,K-1);
	
	printf("%d\n",count);
}
