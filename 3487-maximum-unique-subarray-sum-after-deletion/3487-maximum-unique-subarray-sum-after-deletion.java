class Solution {
    public int maxSum(int[] nums) {
        if (nums.length == 1) return nums[0];
        // 2 - 4 5 - 8
        HashSet<Integer> set = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();

        int curr = 0, max = -101;
        int maxElement = -101;

        for (int num: nums) {
            maxElement = Math.max(num, maxElement);

            if (num <= 0) continue;

            if (!set.contains(num)) {
                curr += num;
                max = Math.max(curr, max);
                set.add(num);
            }
        }

        return Math.max(maxElement, max);
    }
}