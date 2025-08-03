class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combination;

        backtracking(res, candidates, combination, target, 0);

        return res;
    }

    void backtracking(vector<vector<int>>& res, vector<int>& candidates, vector<int>& combination, int target, int idx) {
        int curr = accumulate(combination.begin(), combination.end(), 0);

        if (curr == target) {
            res.push_back(combination);
            return;
        }

        // udah ga mungkin dapet kalo skr dah lebi
        if (curr > target) return;

        for (int i = idx; i < candidates.size(); i ++) {
            combination.push_back(candidates[i]);
            backtracking(res, candidates, combination, target, i);
            combination.pop_back();
        }
    }
};