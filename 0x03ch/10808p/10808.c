#include <stdio.h>
#include <string.h>

int main(){
	int arr[26]={0,};
	char word[100];
	
	scanf("%s",word);
	
	int word_length=strlen(word);
	
	for(int i=0;i<word_length;i++){
		arr[word[i]-97]+=1;
	}
	
	for(int i=0;i<26;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
