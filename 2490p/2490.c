#include <stdio.h>

int main(){
	int noriarr[3][4];
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			scanf("%d",&noriarr[i][j]);
		}
	}
	
	int baecount=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			if(noriarr[i][j]==0){
				baecount+=1;
			}
		}
		if(baecount==0){
			printf("E\n");
		}
		else if(baecount==1){
			printf("A\n");
		}
		else if(baecount==2){
			printf("B\n");
		}
		else if(baecount==3){
			printf("C\n");
		}
		else if(baecount==4){
			printf("D\n");
		}
		baecount=0;
	}
}
			
