#include <stdio.h>
#include <stdlib.h>
int main(){
	int N=0;
	int V=0;
	int vcount=0;
	scanf("%d",&N);
	int*arr;
	arr=(int*)malloc(N*sizeof(int));
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
	}
	
	scanf("%d",&V);
	
	for(int i=0;i<N;i++){
		if(V==arr[i]){
			vcount+=1;
		}
	}
	printf("%d\n",vcount);
}

	
