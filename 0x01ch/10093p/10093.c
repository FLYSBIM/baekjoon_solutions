#include <stdio.h>

int main(){
	long long A=0;
	long long B=0;
	scanf("%lld %lld",&A,&B);
	if(A>B){
		long long temp=A;
		A=B;
		B=temp;
	}
	else if(A==B){
		printf("0\n");	
		return 0;
	}
	printf("%lld\n",B-A-1);
	for(long long i=A+1;i<B;i++){
		printf("%lld ",i);
	}
	printf("\n");
}
