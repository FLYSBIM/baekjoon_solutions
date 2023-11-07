#include <stdio.h>

int main(void){

	int T=0;
	scanf("%d",&T);
	int n=0;
	int arr[11]={0};
	arr[1]=1;
	arr[2]=2;
	arr[3]=4;
	for(int i=0;i<T;i++){
		scanf("%d",&n);
		for(int j=4;j<=n;j++){
			arr[j]=arr[j-1]+arr[j-2]+arr[j-3];
		}
		printf("%d\n",arr[n]);
	}
}
