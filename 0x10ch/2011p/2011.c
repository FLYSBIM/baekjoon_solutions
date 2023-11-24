#include <stdio.h>
#include <string.h>

int main(void){
	char num[5001]="0";
	int dp[5001]={0};	
	scanf("%s",num);
	
	if(num[0]=='\n'){
		printf("0\n");
	}
	
	dp[0]=1;
	if(num[0]=='0'){
		printf("0\n");
		return 0;
	}
	dp[1]=1;
	for(int i=1;i<strlen(num);i++){
		if(((num[i-1]-'0')*10)+(num[i]-'0')<=26){
			if((num[i-1]=='2'||num[i-1]=='1')&&num[i]=='0'){
				dp[i+1]=dp[i-1];
			}
			else if(num[i-1]=='0'){
				if(num[i]!='0'){
					dp[i+1]=dp[i];
				}
				else{
					printf("0\n");
					return 0;
				}
			}
			else{
				dp[i+1]=dp[i]+dp[i-1];
			}
		}
		else if(((num[i-1]-'0')*10)+(num[i]-'0')>26){
			if(num[i-1]>='3'&&num[i]=='0'){
				printf("0\n");
				return 0;
			}
			else{
				dp[i+1]=dp[i];
			}
		}
	}
	printf("%d\n",dp[strlen(num)]);

}
