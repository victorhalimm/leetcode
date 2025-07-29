class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;

        int curr = 0, minSize = 100001;
        while (r < nums.size()) {
            curr += nums[r];

            while (curr >= target && l <= r) {
                minSize = min(minSize, r - l + 1);
                curr -= nums[l];
                l ++;
            }

            r ++;
        }

        return minSize == 100001 ? 0 : minSize;
    }
};