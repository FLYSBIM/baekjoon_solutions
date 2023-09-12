#include <stdio.h>

int main(){
	int arr[7]={0,};
	int min=100;	
	int sum=0;
	for(int i=0;i<7;i++){
		scanf("%d",&arr[i]);
		if(arr[i]%2==1){
			sum+=arr[i];
			if(min>arr[i]){
				min=arr[i];
			}
		}
	}
	if(min==100){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",sum);
	printf("%d\n",min);
}

			

