#include <stdio.h>
#include <string.h>

int max(int a,int b){
	return a>b?a:b;
}

int main(void){
	
	char str1[1001]={0};
	char str2[1001]={0};

	scanf("%s",str1);
	scanf("%s",str2);

	int dp[1001][1000]={0};
	char LCS[1001]={0};

	int leng1=strlen(str1);
	int leng2=strlen(str2);
	int LCSindex=0;
	for(int i=1;i<=leng1;i++){
		for(int j=1;j<=leng2;j++){
			if(str1[i]==str2[j]){
				dp[i][j]=dp[i-1][j-1]+1;
				printf("%c",str1[i]);
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	printf("%d\n",dp[leng1][leng2]);	
}
