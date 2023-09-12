#include <stdio.h>

int main(){
	int A=0;
	int B=0;
	int C=0;
	int arr[10]={0,};
	scanf("%d %d %d",&A,&B,&C);
	int mul=A*B*C;
	
	while(mul!=0){
		arr[mul%10]+=1;
		mul/=10;
	}
	
	for(int i=0;i<10;i++){
		printf("%d\n",arr[i]);
	}	
}
