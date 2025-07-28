class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;

        int l = 0, r = 0;

        while (l <  nums.size()) {
            if (nums[l] < 0) l ++;
            else break;
        }

        l --; 
        if (l == nums.size() - 1) r = nums.size() + 1;
        else r = l + 1;

        while (l >= 0 && r < nums.size()) {
            int lSquared = nums[l] * nums[l];
            int rSquared = nums[r] * nums[r];

            if (lSquared < rSquared) {
                res.push_back(lSquared);
                l --;
            } else {
                res.push_back(rSquared);
                r ++;
            }
        }

        while (l >= 0) {
            res.push_back(nums[l] * nums[l]);
            l --;
        }

        while (r < nums.size()) {
            res.push_back(nums[r] * nums[r]);
            r ++;
        }

        return res;
    }
};