#include <vector>

using namespace std;


class Solution {
public:
    int findMin(vector<int> &nums) {

        if (nums.size() == 1) return nums[0];
        
        int r = nums.size() - 1, l = 0;

        while (l <= r) {

            if (nums[l] < nums[r]) return nums[l];

            if (r - l == 1) {
                return nums[r];
            }

            if (l == r) return nums[l];

            int mid = l + (r - l) / 2;

            if (nums[l] > nums[mid] && l != mid) {
                r = mid;
            }

            else {
                l = mid + 1;
            }

        }

        return nums[l];
    }
};

// 2 1
