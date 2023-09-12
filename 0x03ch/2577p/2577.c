#include <stdio.h>

int main(){

	int countarr[10]={0,};

	int A=0;
	int B=0;
	int C=0;
	scanf("%d %d %d",&A,&B,&C);
	int mul=A*B*C;
	
	while(mul!=0){
		countarr[mul%10]+=1;
		mul/=10;
	}
	for(int i=0;i<10;i++){
		printf("%d\n",countarr[i]);
	}
}
