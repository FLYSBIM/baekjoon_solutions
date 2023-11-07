#include <stdio.h>

int main() {
    int n, k;
    int coins[101];
    int dp[10001] = {0};

    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &coins[i]);
    }

    dp[0] = 1;  // 0원을 만드는 방법은 1가지 (아무 동전도 사용하지 않는 경우)

    for (int i = 1; i <= n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            dp[j] += dp[j - coins[i]];
        }
	for(int j=1;j<=k;j++){
		printf("%d ",dp[j]);
	}
	putchar('\n');
    }

    printf("%d\n", dp[k]);

    return 0;
}
				

		
