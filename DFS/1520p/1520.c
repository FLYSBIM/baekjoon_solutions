/*#include <stdio.h>

int map[500][500]={0};
int visited[500][500]={0};
int M,N;
int route=0;

int dfs(int x,int y,int h){
	if(x<0||x>=N||y<0||y>=M||visited[y][x]==1||map[y][x]>=h){
		return 0;
	}
	
	if(x==N-1&&y==M-1){
		return 1;
	}
	
	route+=dfs(x+1,y,map[y][x]);
	route+=dfs(x-1,y,map[y][x]);
	route+=dfs(x,y+1,map[y][x]);
	route+=dfs(x,y-1,map[y][x]);

	return route; 
}

int main(void){
	scanf("%d%d",&M,&N);

	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			scanf("%d",&map[i][j]);
		}
	}

	int sol=dfs(0,0,map[0][0]);
	printf("%d\n",sol);
}
*/
#include <stdio.h>

#define MAX_SIZE 501

int map[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];
int M, N;

int dfs(int x, int y) {
    if (x == N - 1 && y == M - 1) {
        return 1;  // 도착 지점에 도달한 경우
    }

    if (dp[y][x] != -1) {
        return dp[y][x];  // 이미 계산한 경우 저장된 값을 반환
    }

    dp[y][x] = 0;  // 현재 위치에서의 경우의 수 초기화

    // 현재 위치에서 아래, 위, 오른쪽, 왼쪽으로 이동하면서 내리막길인 경우를 찾음
    if (y + 1 < M && map[y][x] > map[y + 1][x]) {
        dp[y][x] += dfs(x, y + 1);
    }

    if (y - 1 >= 0 && map[y][x] > map[y - 1][x]) {
        dp[y][x] += dfs(x, y - 1);
    }

    if (x + 1 < N && map[y][x] > map[y][x + 1]) {
        dp[y][x] += dfs(x + 1, y);
    }

    if (x - 1 >= 0 && map[y][x] > map[y][x - 1]) {
        dp[y][x] += dfs(x - 1, y);
    }

    return dp[y][x];
}

int main(void) {
    scanf("%d %d", &M, &N);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
            dp[i][j] = -1;  // dp 배열 초기화
        }
    }

    int result = dfs(0, 0);
    printf("%d\n", result);
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
    return 0;
}
	
