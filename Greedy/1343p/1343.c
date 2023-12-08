#include <stdio.h>
#include <string.h>

int main(void){
	char str[50]="";

	scanf("%s",str);

	int countx=0;
	for(int i=0;i<=strlen(str);i++){
		if(str[i]=='X'){
			countx++;
		}
		else if(str[i]=='.'||str[i]=='\0'){
			if(countx%2!=0){
				printf("-1\n");
				return 0;
			}
			int a,b;
			a=countx/4;
			b=countx%4;
			for(int j=i-countx;j<i-countx+a*4;j++){
				str[j]='A';
			}
	
			if(b==2){
				str[i-1]='B';
				str[i-2]='B';
			}
			countx=0;
		}
	}
	printf("%s\n",str);
}
				
			
				
