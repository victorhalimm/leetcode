class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int counter = 1;
        int curr = nums[0];
        for (int i = 0; i < nums.size(); i ++) {
            if (curr != nums[i]) {
                nums[counter ++] = nums[i];
                curr = nums[i];
            }
        }

        return counter;
    }
};