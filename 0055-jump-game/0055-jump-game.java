class Solution {
    public boolean canJump(int[] nums) {
        if (nums.length == 1) return true;

        int maxJumpIdx = -1;
        int maxIdx = nums.length - 1;

        for (int i = 0; i < nums.length; i ++) {
            maxJumpIdx = Math.max(nums[i] + i, maxJumpIdx);

            if (nums[i] == 0 && maxJumpIdx <= i && i != maxIdx) return false;
        }

        return true;
    }
}