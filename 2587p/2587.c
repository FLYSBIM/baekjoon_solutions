#include <stdio.h>

void swap(int *a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int main(){
	int sum=0;
	int arr[5]={0,};
	for(int i=0;i<5;i++){
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4-i;j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}

	int length=sizeof(arr)/sizeof(arr[0]);
	
	printf("%d\n",sum/length);
	printf("%d\n",arr[2]);
}
		
