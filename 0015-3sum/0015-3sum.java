class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
       // -1 -1 0 1 2 4 

       List<List<Integer>> res = new ArrayList<>();

       Arrays.sort(nums);

       for (int i = 0; i < nums.length; i ++) {
            int searched = -1 * nums[i];

            int l = i + 1, r = nums.length - 1;

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            while (l < r && l < nums.length && r >= 0) {
                int total = nums[l] + nums[r];

                if (total == searched) {
                    res.add(List.of(nums[i], nums[l], nums[r]));
                    
                    while (l < nums.length - 1 && nums[l] == nums[l + 1]) l ++;
                    while (r > 0 && nums[r] == nums[r - 1]) r --;
                }

                if (total < searched) l ++;

                else r --;
            }
       }

       return res;
    }
}