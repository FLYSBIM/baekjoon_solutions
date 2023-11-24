#include <stdio.h>

int main() {
    int n, k;
    int coins[101];
    int dp[10001] = {0};

    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &coins[i]);
    }

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    printf("%d\n", dp[k]);

    return 0;
}
				

		
