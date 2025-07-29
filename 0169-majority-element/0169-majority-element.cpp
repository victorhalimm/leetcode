class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int freq = 1;

        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] != candidate) freq --;
            else freq ++;

            if (freq == 0) {
                candidate = nums[i];
                freq ++;
            }
        }

        return candidate;
    }
};