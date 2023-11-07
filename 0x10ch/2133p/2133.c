#include <stdio.h>

int main(void){
	int N=0;
	scanf("%d",&N);

	int dp3[31]={0};
	int dp2[31]={0};
	
	dp2[1]=1;
	dp2[2]=2;
	for(int i=3;i<31;i++){
		dp2[i]=dp2[i-1]+dp2[i-2];
	}
	
	

	dp3[1]=0;
	dp3[2]=3;
	dp3[3]=0;
	for(int i=1;i<=29;i+=2){
		dp[i]=0;
	}
	
	for(int i=4;i<=30;i+=2){
		dp[i]
