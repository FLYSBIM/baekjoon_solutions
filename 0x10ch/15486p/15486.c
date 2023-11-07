#include <stdio.h>

int max(int a,int b){
        return a>b?a:b;
}

int main(void){
        int N=0;
        scanf("%d",&N);

	int cycle=0;
	int p=N%15;
	cycle=cycle/15;

        int arr[16][2]={0};
        int dp[16]={0};
        for(int i=0;i<cycle+1;i++){
		for(int j=0;j<15;j++){
                        scanf("%d %d",&arr[j][0],&arr[j][1]);
                }
		for(int k=1;k<=15;k++){
			int Max=0;
			for(int l=k-1;k>=0;k--){
				if(arr[k][0]<=k-l&&Max<arr[k][1]){
					Max=arr[k][1];
				}
			}
			dp[k]+=Max;
			arr[k][1]+=dp[k];
		}
        }
/*
        for(int i=1;i<=N;i++){
                int Max=0;
                int index=0;
                for(int j=i-1;j>=0;j--){
                        if(arr[j][0]<=i-j&&Max<arr[j][1]){
                                Max=arr[j][1];
                        }
                }
                dp[i]+=Max;
                arr[i][1]+=dp[i];
        }*/

        int sol=dp[0];
        for(int i=1;i<=N;i++){
                sol=max(sol,dp[i]);
        }
        printf("%d\n",sol);
}
