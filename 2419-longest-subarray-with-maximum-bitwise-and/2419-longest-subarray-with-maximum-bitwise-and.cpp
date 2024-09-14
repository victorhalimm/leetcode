class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int maxElement = *max_element(nums.begin(), nums.end());
        int curr = 0;
        int maxLength = 0;

        for (int i = 0; i < nums.size(); i ++) {
            if (nums[i] == maxElement) {
                curr ++;
                maxLength = max(curr, maxLength);
            }
            
            else {
                curr = 0;
            }
        }

        return maxLength;
    }
};
