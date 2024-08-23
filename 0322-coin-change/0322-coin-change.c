int min(int a, int b) {
    return a < b ? a : b;
}

void initDP(int dp[], int len) {
    for (int i = 0; i <= len; i ++) {
        dp[i] = len + 1;
    }
}

int coinChange(int* coins, int coinsSize, int amount) {
    int dp[amount + 1];
    initDP(dp, amount);

    dp[0] = 0;

    for (int i = 1; i <= amount; i ++) {

        for (int j = 0; j < coinsSize; j ++) {
            // if the curr coin is greater than there is no way to reach curr value
            if (i - coins[j] >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
            }
        }
    }

    return dp[amount] != amount + 1 ? dp[amount] : -1;

}