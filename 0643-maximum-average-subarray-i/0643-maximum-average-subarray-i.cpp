class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (k > nums.size()) return -1;

        double curr = 0, res = -20000;
        int l = 0;
        for (int r = 0; r < nums.size(); r ++) {
            curr += nums[r];
            if (r - l + 1 > k) {
                curr -= nums[l ++];
            } 
            if (r - l + 1 == k) res = max(res, (double) curr / (r - l + 1));

        }

        return res;
    }
};