#include <stdio.h>

int main(void){
	int N=0;
	int M=0;
	scanf("%d %d",&N,&M);
	int arr[1000001]={0};
	arr[0]=0;
	
	for(int i=1;i<=N;i++){
		scanf("%d",&arr[i]);
	}

	for(int i=1;i<=N;i++){
		arr[i]=arr[i-1]+arr[i];
	}	


	int start=0;
	int end=0;
	for(int i=0;i<M;i++){
		scanf("%d %d",&start,&end);
		printf("%d\n",arr[end]-arr[start-1]);
	}
}

	
