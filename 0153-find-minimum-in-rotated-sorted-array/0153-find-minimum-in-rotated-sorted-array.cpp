#include <vector>

using namespace std;


class Solution {
public:
    int findMin(vector<int> &nums) {        
        int r = nums.size() - 1, l = 0;

        while (l <= r) {

            if (l == r) return nums[l];
            if (nums[l] < nums[r]) return nums[l];

            if (r - l == 1) {
                return nums[r];
            }


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
