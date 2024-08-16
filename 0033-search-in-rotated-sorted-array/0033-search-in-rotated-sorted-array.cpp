#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size() - 1;

        while (l <= r) {

            int mid = l + (r - l) / 2;


            if (nums[mid] == target) return mid;
            if (nums[r] == nums[l]) return -1;

            if (r - l == 1) {

                if (nums[r] == target) return r;

                if (nums[l] == target) return l;

                else return - 1;

            }


            else if (target < nums[mid] && nums[mid] > nums[l]) {

                if (target == nums[l]) return l;

                if (target < nums[l]) {
                    l = mid;
                }

                else {
                    r = mid - 1;
                }
            }

            else if (target > nums[mid] && nums[mid] < nums[l]) {
                
                if (target == nums[l]) return l;

                if (target > nums[l]) {
                    r = mid - 1;
                }

                else {
                    l = mid;
                }

            }

            else if (target > nums[mid] && nums[mid] > nums[l]) {
                l = mid;
            }

            else {
                r = mid - 1;
            }
        }

        return -1;

    }
};

// 6 7 0 1 2 4 5
// 0