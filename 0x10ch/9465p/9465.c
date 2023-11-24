#include <stdio.h>

int max(int a,int b){
	return a>b?a:b;
}

int main(void){
	int T=0;
	int n=0;
	int arr[2][100001]={0};
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%d",&n);
		for(int j=0;j<2;j++){
			for(int k=1;k<=n;k++){
				scanf("%d",&arr[j][k]);
			}
		}
		
		arr[0][2]+=arr[1][1];
		arr[1][2]+=arr[0][1];
		for(int j=3;j<=n;j++){
			arr[0][j]+=max(max(arr[0][j-2],arr[1][j-2]),arr[1][j-1]);
			arr[1][j]+=max(max(arr[1][j-2],arr[0][j-2]),arr[0][j-1]);
		}
		int sol=0;
		for(int j=0;j<2;j++){
			for(int k=1;k<=n;k++){
				sol=max(sol,arr[j][k]);
			}
		}
		printf("%d\n",sol);
	}
}
		
