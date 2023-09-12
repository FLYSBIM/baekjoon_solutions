#include <stdio.h>

int main(){
	int arr[26]={0,};
	char word[100];
	
	scanf("%s",word);
	
	int word_length=sizeof(arr)/sizeof(arr[0]);
	
	for(int i=0;i<word_length;i++){
		arr[word[i]-97]+=1;
	}
	
	for(int i=0;i<26;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
