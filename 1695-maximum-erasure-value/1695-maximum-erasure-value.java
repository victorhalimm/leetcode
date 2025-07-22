class Solution {
    public int maximumUniqueSubarray(int[] nums) {
        int curr = 0, res = 0;
        
        Set<Integer> set = new HashSet<>();

        int idx = 0;
        int i = 0;
        while (i < nums.length) {
            if (!set.contains(nums[i])) {
                set.add(nums[i]);
                curr += nums[i];
                i ++;
                continue;
            }

            res = Math.max(curr, res);
            curr -= nums[idx];
            set.remove(nums[idx]);
            idx ++;
        }

        res = Math.max(curr, res);

        return res;
    }
}