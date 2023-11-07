#include <stdio.h>
#include <stdlib.h>
int max(int a,int b){
	return a<=b?b:a;
}

int main(void){
	int n=0;
	scanf("%d",&n);
	
	int stair[300]={0};

	int*arr=(int*)malloc(sizeof(int)*n);

	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	stair[0]=arr[0];
	stair[1]=arr[0]+arr[1];
	stair[2]=max(arr[0]+arr[2],arr[1]+arr[2]);

	for(int i=3;i<n;i++){
		if(stair[i-1]==stair[i-2]+arr[i-1]){
			if(stair[i-2]==stair[i-3]){
				stair[i]=arr[i]+max(stair[i-1],stair[i-2]);
			}
			else{
				stair[i]=arr[i]+stair[i-2];
			}
		}
		else if(stair[i-1]!=stair[i-2]+arr[i-1]){
			if(stair[i-1]<=stair[i-2]){
				stair[i]=stair[i-2]+arr[i];
			}
			else{
				stair[i]=stair[i-1]+arr[i];
			}
		}
	}
	printf("%d\n",stair[n-1]);
	free(arr);
}
	
