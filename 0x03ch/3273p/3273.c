#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main(void){
	int n=0;
	int target=0;
	int count=0;
	scanf("%d",&n);
		

	int* arr=NULL;
	
	arr=(int*)malloc(sizeof(int)*n);

	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	qsort(arr,n,sizeof(int),compare);
	
	scanf("%d",&target);
	
	int left=0;
	int right=n-1;

	while(left<right){
		int sum=arr[left]+arr[right];

		if(sum==target){
			count++;
			left++;
			right--;
		}
		else if(sum<target){
			left++;
		}
		else{
			right--;
		}
	}
	

	printf("%d\n",count);
	free(arr);
}
