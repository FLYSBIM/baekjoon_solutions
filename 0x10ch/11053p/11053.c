#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
	return a>b?a:b;
}

int main(void){
	int N=0;
	scanf("%d",&N);

	int*arr=(int*)malloc(sizeof(int)*(N));
	int*dp=(int*)malloc(sizeof(int)*(N));	

	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
		dp[i]=1;
	}
	
	for(int i=1;i<N;i++){
		int index=i-1;
		int biggcount=0;
		int tindex=-1;
		while(index>=0){
			if(arr[i]>arr[index]&&dp[index]>biggcount){
				biggcount=dp[index];
				tindex=index;	
			}
			index--;
		}
		if(tindex!=-1){
			dp[i]+=biggcount;
		}
	}
	
	int sol=dp[0];
	for(int i=1;i<N;i++){
		sol=max(sol,dp[i]);
	}
	printf("%d\n",sol);
	free(arr);
	free(dp);
}

	

	
