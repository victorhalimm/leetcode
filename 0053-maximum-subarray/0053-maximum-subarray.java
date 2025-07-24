class Solution {
    public int maxSubArray(int[] nums) {
        // -2 1 -3 4 -1 2 1 -5 4
        if (nums.length == 0) return -1;

        int maxSum = -10001;
        int currSum = 0;

        for (int num : nums) {
            currSum += num;

            maxSum = Math.max(currSum, maxSum);
            currSum = Math.max(currSum, 0);
        }

        return maxSum;
    }
}