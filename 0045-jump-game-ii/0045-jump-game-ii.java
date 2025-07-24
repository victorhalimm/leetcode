class Solution {
    public int jump(int[] nums) {
        if (nums.length == 1) return 0;
        // 1 1 1 1 
        int currStep = 0;
        int maxJumpIdx = -1;
        int nextMaxJumpIdx = -1;

        for (int i = 0; i < nums.length; i ++) {
            if (i > maxJumpIdx) {
                currStep ++;
                maxJumpIdx = Math.max(maxJumpIdx, nextMaxJumpIdx);
            } 
            nextMaxJumpIdx = Math.max(nextMaxJumpIdx, i + nums[i]);

        }

        return currStep - 1;

    }
}