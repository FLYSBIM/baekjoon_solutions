#include <stdio.h>
#include <string.h>

int max(int a,int b){
	return a>b?a:b;
}

int main(void){
	char str1[1001]={0};
	char str2[1001]={0};
	int dp[1001][1001]={0};
	scanf("%s",str1);
	scanf("%s",str2);
	
	int length1=strlen(str1);
	int length2=strlen(str2);
	
	for(int i=1;i<=length1;i++){
		for(int j=1;j<=length2;j++){
			if(str1[i-1]==str2[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else if(str1[i-1]!=str2[j-1]){
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	printf("%d\n",dp[length1][length2]);
				
}
