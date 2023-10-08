#include <stdio.h>
#include <stdlib.h>
int main(){
	char*arr1=NULL;
	char*arr2=NULL;

	int delc=0;

	int s1[26]={0};
	int s2[26]={0};

	arr1=(char*)malloc(sizeof(char)*1001);
	arr2=(char*)malloc(sizeof(char)*1001);

	scanf("%s",arr1);
	scanf("%s",arr2);
	
	int i=0;
	while(*(arr1+i)!='\0'){
		s1[arr1[i]-'a']++;
		i++;
	}
	i=0;
	while(*(arr2+i)!='\0'){
		s2[arr2[i]-'a']++;
		i++;
	}
	
	for(int i=0;i<26;i++){
		int sum=s1[i]-s2[i];
		if(sum<0){
			sum*=-1;
		}
		delc+=sum;
	}
	
	printf("%d\n",delc);	
		
}
