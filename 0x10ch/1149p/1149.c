#include <stdio.h>

int threemin(int a,int b,int c){
	int min=a;
	if(min>=b){
		min=b;
	}
	
	if(min>=c){
		min=c;
	}
	return min;
}

int twomin(int a,int b){
	return a<b?a:b;
}

int main(void){
	int home[1000][3]={0};
	int N=0;
	scanf("%d",&N);
	
	for(int i=0;i<N;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&home[i][j]);
		}
	}
	
	for(int i=1;i<N;i++){
		home[i][0]+=twomin(home[i-1][1],home[i-1][2]);
		home[i][1]+=twomin(home[i-1][0],home[i-1][2]);
		home[i][2]+=twomin(home[i-1][1],home[i-1][0]);
	}	
	printf("%d\n",threemin(home[N-1][0],home[N-1][1],home[N-1][2]));
}
