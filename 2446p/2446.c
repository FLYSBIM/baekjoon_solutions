#include <stdio.h>

int main(){
	int n=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			printf(" ");
		}
		for(int j=0;j<2*n-2*i-1;j++){
			printf("*");
		}
		printf("\n");
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-2-i;j++){
			printf(" ");
		}
		for(int j=0;j<2*i+3;j++){
			printf("*");
		}
		printf("\n");
	}
}
