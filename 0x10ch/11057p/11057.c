#include <stdio.h>

int main(void){
        int N=0;
        scanf("%d",&N);

        long dp[1001][10]={0};

        for(int i=0;i<=9;i++){
                dp[1][i]=1;
        }

        for(int i=2;i<=N;i++){
                for(int j=0;j<10;j++){
                        for(int k=j;k>=0;k--){
                                dp[i][j]+=dp[i-1][k]%10007;
                        }
                }
        }

        long sol=0;
        for(int i=0;i<10;i++){
                sol+=dp[N][i];
        }
        printf("%ld\n",sol%10007);
}
