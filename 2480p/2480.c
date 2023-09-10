#include <stdio.h>

int main(){
	int arr[3];
	int dicearr[7]={0,};
	
	for(int i=0;i<3;i++){
		scanf("%d",&arr[i]);
		dicearr[arr[i]]+=1;
	}
	int maxint=0;
	for(int i=1;i<7;i++){
		if(dicearr[i]==1 && maxint<i){
			maxint=i;
		}
		else if(dicearr[i]==2){
			printf("%d\n",1000+i*100);
			return 0;
		}
		else if(dicearr[i]==3){
			printf("%d\n",10000+i*1000);
			return 0;
		}
	}
	printf("%d\n",maxint*100);
	return 0;
}
