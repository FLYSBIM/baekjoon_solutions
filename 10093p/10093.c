#include <stdio.h>

int main(){
	int A=0;
	int B=0;
	scanf("%d %d",&A,&B);
	if(A>B){
		int temp=A;
		A=B;
		B=temp;
	}
	printf("%d\n",B-A-1);
	for(int i=A+1;i<B;i++){
		printf("%d ",i);
	}
	printf("\n");
}
