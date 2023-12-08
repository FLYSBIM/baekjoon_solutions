#include <stdio.h>

char map[250][250];
int visited[250][250]={0};
int R,C;
int sheep=0;
int wolf=0;
int dfs(int x,int y){
	if(x<0||x>=C||y<0||y>=R||map[y][x]=='#'||visited[y][x]==1){
		return 0;
	}
	
	visited[y][x]=1;

	if(map[y][x]=='v'){
		wolf++;
	}
	else if(map[y][x]=='o'){
		sheep++;
	}

	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y-1);
	dfs(x,y+1);
	
	return 0;
}

int main(void){
	scanf("%d%d",&R,&C);

	for(int i=0;i<R;i++){
		scanf("%s",map[i]);
	}

	int ans_wolf=0;
	int ans_sheep=0;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(visited[i][j]==0&&map[i][j]!='#'){
				dfs(j,i);
				ans_wolf+=wolf;
				ans_sheep+=sheep;
				wolf=0;
				sheep=0;
			}
		}
	}
	printf("%d %d\n",ans_sheep,ans_wolf);
}
