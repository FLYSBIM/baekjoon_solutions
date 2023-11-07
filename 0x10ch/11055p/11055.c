#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
	return a<b?b:a;
}

int main(void){
	int n=0;
	scanf("%d",&n);
	
	int*arr=(int*)malloc(sizeof(int)*n);
	int*sumarr=(int*)malloc(sizeof(int)*n);
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		sumarr[i]=arr[i];
	}
	
	for(int i=1;i<n;i++){
		int index=i-1;
		int tindex=-1;
		int summ=0;
		while(index>=0){
			if(arr[i]>arr[index]&&summ<sumarr[index]){
				tindex=index;
				summ=sumarr[index];
			}
			index--;
		}
		if(tindex!=-1){
			sumarr[i]+=sumarr[tindex];
		}
	}
	
	int sol=sumarr[0];
	for(int i=1;i<n;i++){
		sol=max(sol,sumarr[i]);
	}	
	printf("%d\n",sol);

	free(arr);
	free(sumarr);
}
