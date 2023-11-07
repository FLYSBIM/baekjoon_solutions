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

	if(pNode->ch=='\0'){
		pNode->ch=ch;
		pNode->prev=getNode('\0');
		pNode->prev->next=pNode;
		return pNode;
	}
	add->next=pNode->next;
	add->prev=pNode;
	if(pNode->next){
		pNode->next->prev=add;
	}
	pNode->next=add;
	return add;
}

Node*delNode(Node*pNode){
	if(pNode->ch=='\0'){
		return pNode;
	}

	Node*prevNode=pNode->prev;
	
	if(pNode->next!=NULL){
		pNode->next->prev=pNode->prev;
	}
	
	if(pNode->prev!=NULL){
		pNode->prev->next=pNode->next;
	}
	free(pNode);
	pNode=NULL;

	return prevNode;
}

void printNode(Node*pNode){
	Node*temp=pNode;
	if(temp->ch=='\0'){
		temp=temp->next;
	}
	while(temp->next!=NULL){
		printf("%c",temp->ch);
		temp=temp->next;
	}
	printf("%c",temp->ch);
	putchar('\n');
}

void freeNode(Node*pNode){
	while(pNode->prev!=NULL){
		pNode=pNode->prev;
	}
	while(pNode!=NULL){
		Node*temp=pNode;
		pNode=pNode->next;
		free(temp);
	}
}
int main(void){

	int Testcase=0;
	scanf("%d",&Testcase);

	char** str=(char**)malloc(sizeof(char*)*Testcase);

	for(int i=0;i<Testcase;i++){
		str[i]=(char*)malloc(sizeof(char)*1000001);
		scanf("%s",str[i]);
	}

	Node**Nodearr=(Node**)malloc(sizeof(Node*)*Testcase);
	for(int i=0;i<Testcase;i++){
		Nodearr[i]=getNode('\0');
	}
	
	//
	Node**head=(Node**)malloc(sizeof(Node*)*Testcase);
	for(int i=0;i<Testcase;i++){
		head[i]=Nodearr[i];
	}
	
	for(int i=0;i<Testcase;i++){
		for(int j=0;j<strlength(str[i]);j++){
			if(str[i][j]=='<'){
				if(Nodearr[i]->prev){
					Nodearr[i]=Nodearr[i]->prev;
				}
			}
			else if(str[i][j]=='>'){
				if(Nodearr[i]->next){
					Nodearr[i]=Nodearr[i]->next;
				}
			}
			else if(str[i][j]=='-'){
				Nodearr[i]=delNode(Nodearr[i]);
			}
			else if(47<str[i][j]&&str[i][j]<58 || 64<str[i][j]&&str[i][j]<91 || str[i][j]>96&&str[i][j]<123){
				Nodearr[i]=addNode(Nodearr[i],str[i][j]);
			}
		}
	}/*
	for(int i=0;i<Testcase;i++){
		printNode(Nodearr[i]);
	}*/
	for(int i=0;i<Testcase;i++){
		printNode(head[i]);
	}
	
	for(int i=0;i<Testcase;i++){
		free(str[i]);
	}
	free(str);
	for(int i=0;i<Testcase;i++){
		freeNode(Nodearr[i]);
	}
	free(head);
	free(Nodearr);
}


