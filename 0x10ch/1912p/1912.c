#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
	return a<=b?b:a;
}

int main(void){
	int n=0;
	scanf("%d",&n);
	
	int* arr=(int*)malloc(sizeof(int)*n);
	int* sumarr=(int*)malloc(sizeof(int)*n);	

	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	sumarr[0]=arr[0];
	
	for(int i=1;i<n;i++){
		sumarr[i]=max(arr[i],sumarr[i-1]+arr[i]);
	}
	
	int sol=sumarr[0];
	for(int i=1;i<n;i++){
		sol=max(sol,sumarr[i]);
	}
	
	printf("%d\n",sol);

	free(arr);
	free(sumarr);
}
