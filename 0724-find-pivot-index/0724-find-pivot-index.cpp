class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;

        for (int num: nums) {
            sum += num;
        }

        int leftSum = 0;
        int currSum = sum;
        for (int i = 0; i < nums.size(); i ++) {
            currSum -= nums[i];
            if (i > 0) leftSum += nums[i - 1];
            
            int rightSum = currSum - leftSum;

            if (leftSum == rightSum) return i;

            currSum = sum;
        }

        return -1;
    }
};