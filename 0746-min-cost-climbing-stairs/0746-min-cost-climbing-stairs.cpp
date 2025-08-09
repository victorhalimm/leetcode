class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = cost[0], prev1 = cost[1];
        int res = 0;
        for (int i = 2; i < cost.size(); i ++) {
            res = min(prev1 + cost[i], prev2 + cost[i]);
            prev2 = prev1;
            prev1 = res;
        }

        return min(prev1, prev2);
    }
};