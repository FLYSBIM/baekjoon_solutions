#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char data;
	struct Node*prev;
	struct Node*next;
}Node;

int main(){
	

	char str[100001];
	fgets(str,100001,stdin);
	str[strcspn(str,"\n")]='\0';
	printf("%s\n",str);
	
	Node head;
	head.data=str[0];
	
	int i=1
	while(str[i]!='NULL'){
		
	
	int M=0;
	scanf("%d",&M);
	char command;

	for(int i=0;i<M;i++){
		scanf("%c",&command);
		
		switch(command){
			case 'P':
			
			case 'L':
			
			case 'D':

			case 'B':
		}
	}



}
	
