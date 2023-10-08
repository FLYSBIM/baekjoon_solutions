#include <stdio.h>

int main(void){
	int arr[2][6]={0};

	int N=0;
	int K=0;
	int grade=0;
	int s=0;
	int count=0;

	scanf("%d %d",&N,&K);
	
	for(int i=0;i<N;i++){
		scanf("%d %d",&s,&grade);
		arr[s][grade-1]++;
	}

	for(int i=0;i<2;i++){
		for(int j=0;j<6;j++){
			count+=arr[i][j]/K;
			if(arr[i][j]%K!=0){
				count++;
			}
		}
	}

	printf("%d\n",count);
}
