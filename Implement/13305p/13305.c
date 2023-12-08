#include <stdio.h>

int main(void){
	int oil[100001]={0};
	int road[100001]={0};

	int N=0;
	scanf("%d",&N);

	for(int i=0;i<N-1;i++){
		scanf("%d",&road[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&oil[i]);
	}

	int cost=0;
	int min_price_index=-1;
	int pre_min_price_index=-1;
	while(min_price_index!=0){
		int min_price=1000000001;
		if(min_price_index==-1){
			for(int i=0;i<N-1;i++){
				if(min_price>oil[i]){
					min_price_index=i;
					min_price=oil[i];
				}
			}
		}
		else if(min_price_index!=-1){
			for(int i=0;i<pre_min_price_index;i++){
				if(min_price>oil[i]){
					min_price_index=i;
					min_price=oil[i];
				}
			}
		}
		int roadsum=0;
		if(pre_min_price_index==-1){
			for(int i=min_price_index;i<N-1;i++){
				roadsum+=road[i];
			}
		}
		else{
			for(int i=min_price_index;i<pre_min_price_index;i++){
				roadsum+=road[i];
			}
		}
		pre_min_price_index=min_price_index;
		cost+=(roadsum*min_price);
	}
	printf("%d\n",cost);
}
