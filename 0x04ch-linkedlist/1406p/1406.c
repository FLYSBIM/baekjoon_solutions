#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	char ch;
	struct Node*next;
	struct Node*back;
}Node;

int strlength(char*str){
	int strlength=0;
	while(str[strlength]!='\0'){
		strlength++;
	}
	return strlength;
}

void printNode(Node *pNode){
	while(1){
		if(pNode->back==NULL){
			break;
		}
		pNode=pNode->back;
	}
	
	while(1){
		if(pNode->next==NULL){
			printf("%c",pNode->ch);
			break;
		}

		if(pNode->ch!='\0'){
			printf("%c",pNode->ch);
		}
		pNode=pNode->next;
	}
	putchar('\n');
}

Node*delNode(Node*pNode){
	Node*backNode=pNode->back;
	if(pNode->ch=='\0'){
		return pNode;
	}	
	

	if(pNode->back!=NULL){
		pNode->back->next=pNode->next;
	}
	
	if(pNode->next!=NULL){
		pNode->next->back=pNode->back;
	}

	free(pNode);
	pNode=NULL;

	return backNode;
}

void freeNode(Node*tNode){
	while(tNode->back!=NULL){
		tNode=tNode->back;
	}
	while(tNode!=NULL){
		Node*temp=tNode;
		tNode=tNode->next;
		free(temp);
	}
}

Node* getNode(char ch){
	Node*get=(Node*)malloc(sizeof(Node));
	get->ch=ch;
	get->next=NULL;
	get->back=NULL;
	return get;
}

Node* addNode(Node*pNode,char ch){
	Node*ad=getNode(ch);

	if(pNode->ch=='\0'){
		pNode->ch=ch;
		pNode->back=getNode('\0');
		pNode->back->next=pNode;
		return pNode;
	}

	ad->next=pNode->next;
	ad->back=pNode;	
	if(pNode->next){
		pNode->next->back=ad;
	}
	pNode->next=ad;
	return ad;
}

int main(void){

	char str[600001]="0";
	scanf("%s",str);

	int commandN=0;
	scanf("%d",&commandN);
	
	int strleng=strlength(str);

	Node*start=getNode('\0');	
	Node*pNode=start;

	for(int i=0;i<strleng;i++){
		Node*tnode=getNode(str[i]);
	
		tnode->back=pNode;
		pNode->next=tnode;
		pNode=pNode->next;
	}
		

	for(int i=0;i<commandN;i++){
		char command;
		scanf(" %c",&command);
		if(command=='L'){
			if(pNode->back!=NULL){
				pNode=pNode->back;
			}
		}
		else if(command=='D'){
			if(pNode->next!=NULL){
				pNode=pNode->next;
			}
		}
		else if(command=='B'){
			if(pNode!=NULL){
				pNode=delNode(pNode);
			}
		}
		else if(command=='P'){
			char addchar='\0';
			scanf(" %c",&addchar);
			pNode=addNode(pNode,addchar);
		}	
	}
	printNode(pNode);
	freeNode(pNode);
}
