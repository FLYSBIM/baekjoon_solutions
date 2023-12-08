#include <stdio.h>
#include <string.h>

int map[26][26]={0};
int visited[26][26]={0};
int N;

int dfs(int x,int y){
	if(x<0||x>=N||y<0||y>=N||map[x][y]==0||visited[x][y]==1){
		return 0;
	}
	
	visited[x][y]=1;
	int area=1;
	
	area+=dfs(x+1,y);
	area+=dfs(x-1,y);
	area+=dfs(x,y+1);
	area+=dfs(x,y-1);
	
	return area;
}

int main(void){
	scanf("%d",&N);

	for(int i=0;i<N;i++){
		char building[26]="0";
		scanf("%s",building);
		for(int j=0;j<N;j++){
			map[i][j]=building[j]-'0';
		}
	}
	int answer[25*25+1]={0};
	int count=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(map[i][j]&&!visited[i][j]){
				answer[count++]=dfs(i,j);
			}
		}
	}

	for(int i=0;i<count;i++){
		for(int j=0;j<count-i-1;j++){
			if(answer[j]>answer[j+1]){
				int temp=answer[j];
				answer[j]=answer[j+1];
				answer[j+1]=temp;
			}
		}
	}
	printf("%d\n",count);
	for(int i=0;i<count;i++){
		printf("%d\n",answer[i]);
	}
}
