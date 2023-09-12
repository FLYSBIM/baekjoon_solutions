#include <stdio.h>
#include <stdlib.h>

int main(){
	int y=10;
	int m=15;
	int ysum=0;
	int msum=0;
	
	int N=0;
	
	int *arr;
	scanf("%d",&N);
	arr=(int*)malloc(N*sizeof(int));
	
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
		ysum+=(arr[i]/30+1)*y;
		msum+=(arr[i]/60+1)*m;
	}
	
	if(ysum==msum){
		printf("Y M %d\n",ysum);
	}
	else if(ysum>msum){
		printf("M %d\n",msum);
	}	
	else if(ysum<msum){
		printf("Y %d\n",ysum);
	}	
}
