#include <stdio.h>

int main(){
	int n=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			printf(" ");
		}
		for(int j=2*n-2*i-1;j>0;j--){
			printf("*");
		}
		printf("\n");
	}
}