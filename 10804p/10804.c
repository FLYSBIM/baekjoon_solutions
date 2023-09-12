#include <stdio.h>
#include <stdlib.h>
void reverse(int a,int b,int *arr){
	int n=b-a+1;
	int*arr2;
	arr2=(int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++){
		arr2[i]=arr[b-i];
	}
	for(int i=0;i<n;i++){
		arr[a+i]=arr2[i];
	}
}
		
		

int main(){
	
	int mat[10][2];
	for(int i=0;i<10;i++){
		for(int j=0;j<2;j++){
			scanf("%d",&mat[i][j]);
		}
	}
	int arr[21]={0,};
	for(int i=1;i<21;i++){
		arr[i]=i;
	}
		
	for(int i=0;i<10;i++){
		reverse(mat[i][0],mat[i][1],arr);
	}
	
	for(int i=1;i<21;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
