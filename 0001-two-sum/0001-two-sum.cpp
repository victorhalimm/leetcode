#include <unordered_map> 
using namespace std; 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> arrMap;

        vector<int> sol;

        for (int i = 0; i < nums.size() ; i++) {

            int search = target - nums[i];

            if (!arrMap[search])  arrMap[nums[i]] = i + 1;
                
            else {
                sol.push_back(arrMap[search] - 1);
                sol.push_back(i);

                return sol;
            }
        }

        return sol;
    }
};