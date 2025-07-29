class Solution {
public:
    // 3 2 1 6
    // 6
    // 

    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixMap;
        int total = 0;

        // this one is to handle case if subarray starts from 0
        prefixMap[0] = 1;

        int res = 0;

        for (int i = 0; i < nums.size(); i ++) {
            total += nums[i];
            int remain = total - k;

            if (prefixMap[remain]) res += prefixMap[remain];
            prefixMap[total] ++;
        }

        return res;
    }
};