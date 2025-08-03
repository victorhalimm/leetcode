class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(nums, curr, res, 0);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& curr, vector<vector<int>>& res, int idx) {
        res.push_back(curr);

        for (int i = idx; i < nums.size(); i ++) {
            curr.push_back(nums[i]);
            backtrack(nums, curr, res, i + 1);
            curr.pop_back();
        }
    }
};