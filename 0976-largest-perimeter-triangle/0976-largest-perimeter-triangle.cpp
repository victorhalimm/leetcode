class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());

        int size = nums.size();
        int res = 0;

        for (int i = 0; i < size - 2; i ++) {
            int perimeter = nums[i] + nums[i + 1] + nums[i + 2];
            if (nums[i] + nums[i + 1] > nums[i + 2]) res = perimeter;
        }

        return res;
    }
};