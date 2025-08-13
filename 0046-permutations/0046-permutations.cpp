class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr, used(nums.size());
        backtrack(res, nums, curr, used, 0);

        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& nums, vector<int>& curr, vector<int>& used, int idx) {

        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }
        if (idx >= nums.size()) return;

        for (int i = 0; i < nums.size(); i ++) {
            if (used[i]) continue;

            used[i] = 1;
            curr.push_back(nums[i]);
            backtrack(res, nums, curr, used, idx + 1);
            curr.pop_back();
            used[i] = 0;
        }
    }
};