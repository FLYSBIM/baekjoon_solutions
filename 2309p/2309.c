#include <stdio.h>

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int main(){
	int sum=0;
	int arr[9]={0,};
	for(int i=0;i<9;i++){
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	int target=sum-100;
	for(int i=0;i<8;i++){
		for(int j=0;j<8-i;j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
	}
	int l_point=0;
	int r_point=8;
	while(l_point<r_point && arr[l_point]+arr[r_point]!=target){
		if(target<arr[l_point]+arr[r_point]){
			r_point-=1;
		}
		else if(target>arr[l_point]+arr[r_point]){
			l_point+=1;
		}
		
	}
	for(int i=0;i<9;i++){
		if(i!=r_point && i!=l_point){
			printf("%d\n",arr[i]);
		}
	}
}
