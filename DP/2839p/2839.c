#include <stdio.h>

int min(int a,int b){
	return a<=b?a:b;
}

int main(void){
	int sugar[5001]={0};
	
	sugar[3]=1;
	sugar[5]=1;

	int N=0;
	scanf("%d",&N);
	
	for(int i=6;i<=N;i++){
		if(sugar[i-3]>=1 && sugar[i-5]>=1){
			
			sugar[i]=min(sugar[i-5],sugar[i-3])+1;
		}
		else if(sugar[i-3]==0 && sugar[i-5]>=1){
			sugar[i]=sugar[i-5]+1;
		}
		else if(sugar[i-5]==0 && sugar[i-3]>=1){
			sugar[i]=sugar[i-3]+1;
		}
	}
	
	if(sugar[N]==0){
		printf("-1\n");
	}
	else{
		printf("%d\n",sugar[N]);
	}
}
