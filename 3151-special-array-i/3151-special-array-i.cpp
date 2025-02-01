class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if (nums.size() == 1) return true;

        for (int i = 0; i < nums.size() - 1; i ++) {
            bool parity = nums[i] % 2 == 0;

            if (parity == nums[i + 1] % 2 == 0) return false;
        }

        return true;
    }
};