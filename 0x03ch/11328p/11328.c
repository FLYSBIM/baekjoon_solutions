#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
	int N=0;

	scanf("%d",&N);

	char***str=NULL;


	str=(char***)malloc(sizeof(char**)*N);

	for(int i=0;i<N;i++){
		str[i]=(char**)malloc(sizeof(char*)*2);
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<2;j++){
			str[i][j]=(char*)malloc(sizeof(char)*1001);
		}
	}


	for(int i=0;i<N;i++){
		for(int j=0;j<2;j++){
			scanf("%s",str[i][j]);
		}
	}

	for(int i=0;i<N;i++){
		int arr[2][26]={0};
		
		for(int j=0;j<2;j++){
			for(int k=0;str[i][j][k]!='\0';k++){
				arr[j][str[i][j][k]-'a']++;
			}
		}
		
		int isSame=1;
		
		for(int j=0;j<26;j++){
			if(arr[0][j]!=arr[1][j]){
				isSame=0;
				break;
			}
		}
		if(isSame)
			printf("Possible\n");
		else
			printf("Impossible\n");

	}




	for(int i=0;i<N;i++){
		for(int j=0;j<2;j++){
			free(str[i][j]);
		}
	}

	for(int i=0;i<N;i++){
		free(str[i]);
	}	

	free(str);
}
