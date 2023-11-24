#include <stdio.h>

int max(int a,int b){
	return a>b?a:b;
}

int min(int a,int b){
	return a>b?b:a;
}

int main(void){
	int dp1[100001][3]={0};
	int dp2[100001][3]={0};

	int n=0;
	scanf("%d",&n);

	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&dp1[i][j]);
			dp2[i][j]=dp1[i][j];
		}
	}

	for(int i=2;i<=n;i++){
		dp1[i][0]+=max(dp1[i-1][1],dp1[i-1][0]);
		dp1[i][1]+=max(dp1[i-1][1],max(dp1[i-1][0],dp1[i-1][2]));
		dp1[i][2]+=max(dp1[i-1][2],dp1[i-1][1]);
	}

	int maxsol=max(max(dp1[n][0],dp1[n][1]),dp1[n][2]);
	
	for(int i=2;i<=n;i++){
                dp2[i][0]+=min(dp2[i-1][1],dp2[i-1][0]);
                dp2[i][1]+=min(dp2[i-1][1],min(dp2[i-1][0],dp2[i-1][2]));
                dp2[i][2]+=min(dp2[i-1][2],dp2[i-1][1]);
        }

	int minsol=min(min(dp2[n][0],dp2[n][1]),dp2[n][2]);
	printf("%d %d\n",maxsol,minsol);
}


