#include <stdio.h>

int max(int a,int b){
	return a>b?a:b;
}

int main(void){
	int arr[500][500]={0};
	
	int n=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			scanf("%d",&arr[i][j]);
		}
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<=i;j++){
			if(j==0){
				arr[i][j]+=arr[i-1][j];
			}
			else if(j==i){
				arr[i][j]+=arr[i-1][j-1];
			}
			else{
				arr[i][j]+=max(arr[i-1][j-1],arr[i-1][j]);
			}
		}
	}
	int Max=arr[n-1][0];
	for(int i=1;i<n;i++){
		Max=max(Max,arr[n-1][i]);
	}
	printf("%d\n",Max);
}

			
