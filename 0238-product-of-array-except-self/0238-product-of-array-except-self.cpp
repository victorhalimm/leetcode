#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum = 1;
        int zero_count = 0;
        int last_zero_idx = -1;
        int len = nums.size();

        for (int i = 0; i < len; i ++) {
            if (nums[i] == 0) {
                zero_count ++;
                last_zero_idx = i;
                nums[i] = 1;
            }

            sum *= nums[i];
        }

        vector<int> res;

        for (int i = 0; i < len; i ++) {
            
            if (zero_count > 1)
                res.push_back(0);
            
            else if (zero_count == 1) {
                
                if (i == last_zero_idx) res.push_back(sum / nums[i]);
                else res.push_back(0);

            }
            
            else 
                res.push_back(sum / nums[i]);
        }

        return res;
    }
};