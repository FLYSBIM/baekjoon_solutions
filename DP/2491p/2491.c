#include <stdio.h>

int max(int a,int b){
	return a>b?a:b;
}

int main(void){
	int N=0;
	
	int sq[100001]={0};
	
	int dpup[100001]={0};
	int dpdown[100001]={0};

	scanf("%d",&N);

	for(int i=0;i<=N;i++){
		dpup[i]=1;
		dpdown[i]=1;
	}
	
	for(int i=1;i<=N;i++){
		scanf("%d",&sq[i]);
	}

	for(int i=2;i<=N;i++){
		if(sq[i]>=sq[i-1]){
			dpup[i]=dpup[i-1]+1;
		}

		if(sq[i]<=sq[i-1]){
			dpdown[i]=dpdown[i-1]+1;
		}
	}
	int sol=dpup[1];
	for(int i=2;i<=N;i++){
		sol=max(sol,dpup[i]);
	}
	for(int i=1;i<=N;i++){
		sol=max(sol,dpdown[i]);
	}
	printf("%d\n",sol);
}
