#include <stdio.h>

char map[20][20];
int visited[20][20]={0};
int R,C;
int on_off[26]={0};

int dfs(int x,int y){
	if(x<0||x>=C||y<0||y>=R||visited[y][x]==1||on_off[map[y][x]-'A']==1){
		return 0;
	}
	
	visited[y][x]=1;
	on_off[map[y][x]-'A']=1;
	int area=1;
	
	area+=dfs(x+1,y);
	area+=dfs(x-1,y);
	area+=dfs(x,y+1);
	area+=dfs(x,y-1);
	
	return arae;
}

int main(void){
	scanf("%d%d",&R,&C);

	for(int i=0;i<R;i++){
		scanf("%s",map[i]);
	}

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(visited[y][x]
}

