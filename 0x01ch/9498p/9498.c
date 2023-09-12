#include <stdio.h>

int main(){

int exam_score=0;
scanf("%d",&exam_score);

if(90<=exam_score && exam_score<=100){
	printf("A\n");}
else if(80<=exam_score && exam_score<=89){
	printf("B\n");}
else if(70<=exam_score && exam_score<=79){
	printf("C\n");}
else if(60<=exam_score && exam_score<=69){
	printf("D\n");}
else{
	printf("F\n");
}
}






