#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	char ch;
	struct Node*next;
	struct Node*prev;
}Node;

int strlength(char*str){
	char*temp=str;
	int index=0;
	while(str[index]!='\0'){
		index++;
	}
	return index;
}
		
Node*getNode(char ch){
	Node*rNode=(Node*)malloc(sizeof(Node));
	rNode->ch=ch;
	rNode->next=NULL;
	rNode->prev=NULL;
	return rNode;
}

Node*addNode(Node*pNode,char ch){
	Node*add=getNode(ch);
	add->prev=pNode;
	if(pNode->next){
		add->next=pNode->next;
	}
	pNode->next=add;
	return add;
}

Node*delNode(Node*pNode){
	if(pNode->ch=='\0'){
		return pNode;
	}

	Node*prevNode=pNode->prev;
	
	if(pNode->next){
		pNode->next->prev=pNode->prev;
	}
	
	if(pNode->prev){
		pNode->prev->next=pNode->next;
	}
	free(pNode);
	pNode=NULL;

	return prevNode;
}

void printNode(Node*pNode){
	Node*temp=pNode;
	while(temp->prev!=NULL){
		temp=temp->prev;
	}
	while(temp->next!=NULL){
		printf("%c",temp->ch);
		temp=temp->next;
	}
	printf("%c",temp->ch);
	putchar('\n');
}

int main(void){

	int Testcase=0;
	scanf("%d",&Testcase);

	char** str=(char**)malloc(sizeof(char*)*Testcase);

	for(int i=0;i<Testcase;i++){
		str[i]=(char*)malloc(sizeof(char)*1000001);
		scanf("%s",str[i]);
	}

	Node*start=getNode('\0');
	Node*pNode=start;

	Node**Nodearr=(Node**)malloc(sizeof(Testcase));
	for(int i=0;i<Testcase;i++){
		Nodearr[i]=getNode('\0');
	}

	for(int i=0;i<Testcase;i++){
		for(int j=0;j<strlength(str[i]);j++){
			if(str[i][j]=='<'){
				if(pNode->prev){
					pNode=pNode->prev;
				}
			}
			else if(str[i][j]=='>'){
				if(pNode->next){
					pNode=pNode->next;
				}
			}
			else if(str[i][j]=='-'){
				pNode=delNode(pNode);
			}
			else if(47<str[i][j]&&str[i][j]<58 || 64<str[i][j]&&str[i][j]<91 || str[i][j]>96&&str[i][j]<123){
				pNode=addNode(pNode,str[i][j]);
			}
		}
	}
	printNode(pNode);

	for(int i=0;i<Testcase;i++){
		free(str[i]);
	}
	free(str);
}


