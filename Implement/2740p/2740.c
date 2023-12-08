#include <stdio.h>

int main(void){
	int matrix1[100][100]={0};
	int matrix2[100][100]={0};
	int matrix3[100][100]={0};
	int N,M,K;

	scanf("%d%d",&N,&M);

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d",&matrix1[i][j]);
		}
	}

	scanf("%d%d",&M,&K);

	for(int i=0;i<M;i++){
		for(int j=0;j<K;j++){
			scanf("%d",&matrix2[i][j]);
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<K;j++){
			for(int k=0;k<M;k++){
				matrix3[i][j]+=matrix1[i][k]*matrix2[k][j];
			}
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<K;j++){
			printf("%d ",matrix3[i][j]);
		}
		printf("\n");
	}
}
