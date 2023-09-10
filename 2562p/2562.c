#include <stdio.h>

int main(){
	int arr[9]={0,};
	int maxint=0;
	int maxintindex=0;
	for(int i=0;i<9;i++){
		scanf("%d",&arr[i]);
		if(maxint<arr[i]){
			maxint=arr[i];
			maxintindex=i+1;
		}
	}
	printf("%d\n",maxint);
	printf("%d\n",maxintindex);
}
	
