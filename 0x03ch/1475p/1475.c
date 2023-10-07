#include <stdio.h>

int main(void){
	int N=0;
	scanf("%d",&N);
	
	int arr[10]={0,};
	
	while(N!=0){
		arr[N%10]+=1;
		N/=10;
	}
	arr[6]=arr[6]+arr[9];

	if(arr[6]%2==0){
		arr[6]/=2;
	}
	else{
		arr[6]/=2;
		arr[6]++;
	}	

	int max=arr[0];
	
	for(int i=1;i<9;i++){
		if(max<arr[i]){
			max=arr[i];
		}
	}
	
	printf("%d\n",max);
}
