class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

        return memo(dp, coins, amount, 0);
    }

    int memo(vector<vector<int>> &dp, vector<int>& coins, int amount, int curr) {
        if (amount == 0) {
            return 1;
        }

        if (curr >= coins.size() || amount < 0) return 0;

        if (dp[curr][amount] != -1) return dp[curr][amount];

        return dp[curr][amount] = memo(dp, coins, amount - coins[curr], curr) + memo(dp, coins, amount, curr + 1);
    }
};