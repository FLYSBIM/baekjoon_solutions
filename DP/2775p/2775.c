#include <stdio.h>

int main(void){
	int arr[15][15]={0};
	
	for(int i=0;i<15;i++){
		arr[0][i]=i;
	}

	for(int i=1;i<15;i++){
		for(int j=1;j<=14;j++){
			for(int k=j;k>=1;k--){
				arr[i][j]+=arr[i-1][k];
			}
		}
	}
	int k=0;
	int n=0;
	int T=0;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d%d",&k,&n);
		printf("%d\n",arr[k][n]);
	}
}
			
