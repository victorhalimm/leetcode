class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; i ++) {
            int stonks = prices[i + 1] - prices[i];
            if (stonks > 0) 
                profit += stonks;
        }

        return profit;
    }
};