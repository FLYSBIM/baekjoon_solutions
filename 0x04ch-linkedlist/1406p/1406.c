#include <stdio.h>

typedef struct Node{
	char ch;
	struct Node*next;
	struct Node*back;
}Node;

void del(Node *node){
	if(node->back){
		node->back->next=node->next;
	}
	if(node->next){
		node->next->back=node->back;
	}
	node->next=NULL;
	node->back=NULL;
}
int main(void){
	char str[100001]={0};
	int i=0;
	int n=0;
	scanf("%s",str);
	while(str[i]!='\0'){
		i++;
	}

	Node narr[i];
	Node*nownode=NULL;
	for (int j = 0; j < i; j++) {
        	narr[j].ch = str[j];
        	if (j < i - 1) {
        	    narr[j].next = &narr[j + 1];
            	    narr[j + 1].back = &narr[j];
        	} 
		else {
            		narr[j].next = NULL;
        	}
    	}		
	narr[0].back=NULL;
	nownode=&narr[i-1]; 

	scanf("%d",&n);
	char com='\0';
	for(int k=0;k<n;k++){
		scanf(" %c",&com);
		
		switch(com){
			case 'P':		
				
			case 'B':
				if (nownode&&nownode->back) {
        				Node* toDel = nownode;
        				nownode = nownode->back;
        				del(toDel);
    				}
				break;

			case 'L':
				nownode=nownode->back;
				break;
			case 'D':
				nownode=nownode->next;
				break;
		}
	}

	for(int j=0;j<i;j++){
		printf("%c",narr[j].ch);
	}


	printf("\n");
		
		
}
