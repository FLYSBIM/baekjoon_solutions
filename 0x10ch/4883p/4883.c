#include <stdio.h>

int min(int a,int b){
        return a<b?a:b;
}

int main(void){

        int dp[100001][3]={0};
        int graph[100001][3]={0};
        int index=1;
        while(1){
                int n=0;
                scanf("%d",&n);
                if(n==0){
                        break;
                }
                for(int i=0;i<n;i++){
                        scanf("%d%d%d",&graph[i][0],&graph[i][1],&graph[i][2]);
                }
                dp[0][0]=1000000;
                dp[0][1]=graph[0][1];
                dp[0][2]=graph[0][1]+graph[0][2];

                for(int i=1;i<n;i++){
                        dp[i][0]=min(graph[i][0]+dp[i-1][0],graph[i][0]+dp[i-1][1]);
                        dp[i][1]=min(min(dp[i][0]+graph[i][1],dp[i-1][0]+graph[i][1]),min(dp[i-1][1]+graph[i][1],dp[i-1][2]+graph[i][1]));
                        dp[i][2]=min(dp[i-1][2]+graph[i][2],min(dp[i-1][1]+graph[i][2],dp[i][1]+graph[i][2]));
                }

                printf("%d. %d\n",index++,dp[n-1][1]);
        }
}
