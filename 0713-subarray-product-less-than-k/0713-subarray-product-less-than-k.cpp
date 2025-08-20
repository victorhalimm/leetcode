class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int curr = 1, l = 0, res = 0;

        for (int r = 0; r < nums.size(); r ++) {
            curr *= nums[r];

            while (curr >= k && l < nums.size()) {
                curr /= nums[l ++];
            }

            res += (r - l + 1);
        }

        return res;
    }
};