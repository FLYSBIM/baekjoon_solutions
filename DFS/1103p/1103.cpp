/*#include <iostream>
#include <vector>

using namespace std;

char map[50][50];
int tmpmap[50][50];
int dp[50][50];
int N,M;

int dfs(int x,int y){
	if(x<0||x>=M||y<0||y>=N||map[y][x]=='H'||dp[y][x]){
		return 1;
	}
	
	dp[y][x]=0;
	
	dp[y][x]+=dfs(x+(map[y][x]-'0'),y);
	dp[y][x]+=dfs(x-(map[y][x]-'0'),y);
	dp[y][x]+=dfs(x,y+(map[y][x]-'0'));
	dp[y][x]+=dfs(x,y-(map[y][x]-'0'));

	return dp[y][x];
}

int main(void){
	cin>>N>>M;
	
	for(int i=0;i<N;i++){
		cin>>map[i];
	}


	dfs(0,0);
	for(int k=0;k<N;k++){
		for(int l=0;l<M;l++){
			cout<<dp[k][l]<<" ";
		}
		cout<<endl;
	}
			cout<<endl;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}	
	cout<<endl;

}*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
vector<string> board;
vector<vector<int> > dp;
vector<vector<bool> > visited;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y) {
    // 범위를 벗어나면 0 반환
    if (x < 0 || x >= N || y < 0 || y >= M || board[x][y] == 'H') {
        return 0;
    }

    // 이미 방문한 곳이면 무한 루프에 빠지는 것을 방지하기 위해 -1 반환
    if (visited[x][y]) {
        cout << -1;
        exit(0);
    }

    // 이미 계산한 결과가 있다면 반환
    if (dp[x][y] != -1) {
        return dp[x][y];
    }

    visited[x][y] = true;
    dp[x][y] = 0;

    // 상하좌우로 이동
    for (int k = 0; k < 4; k++) {
        int nx = x + (board[x][y] - '0') * dx[k];
        int ny = y + (board[x][y] - '0') * dy[k];

        dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }

    visited[x][y] = false;
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    board.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    // 초기화
    dp.assign(N, vector<int>(M, -1));
    visited.assign(N, vector<bool>(M, false));

    // 시작 위치에서 DFS 호출
    int result = dfs(0, 0);
    cout << result;
	
for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                        cout<<dp[i][j]<<" ";
                }
                cout<<endl;
        }     
    return 0;
}

