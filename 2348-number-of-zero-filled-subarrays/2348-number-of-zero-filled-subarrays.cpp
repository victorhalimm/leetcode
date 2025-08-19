class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // 00 -> 2 + 1 = 3
        // 000 -> 3 + 2 = 5
        // 0000 -> 4 + 3 + 2 = 9
        // 2 -> 3
        // 3 -> 5
        // 4 -> 9
        vector<long long> dp(nums.size() + 1, -1);
        dp[0] = 0;
        dp[1] = 1;

        long long res = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == 0 && i < nums.size() - 1) count ++;

            else {
                if (nums[i] == 0) count ++;
                
                if (count == 0) continue;

                if (dp[count - 1] != -1) dp[count] = dp[count - 1] + count;
                
                else {
                    for (int i = 1; i <= count; i ++) dp[i] = dp[i - 1] + i;
                }
                res += dp[count];
                count = 0;
            }
        }

        return res;
    }
};