class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if (nums.empty()) return {-1, -1};

        int l = 0, r = nums.size() - 1;

        int mid = -1;

        while (l <= r) {

            mid = l + (r - l) / 2;

            if (target == nums[mid])
                break;

            else if (target < nums[mid]) {
                r = mid - 1;
            }

            else {
                l = mid + 1;
            }

        }

        if (nums[mid] != target)
            return {-1, -1};

        l = r = mid;

        while (l - 1 >= 0 && nums[l - 1] == target)
            l --;

        while (r + 1 < nums.size() && nums[r + 1] == target)
            r ++;

        return {l, r};
    }
};