class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        set<vector<int>> res;

        sort(candidates.begin(), candidates.end());

        backtracking(curr, candidates, res, target, 0, 0);

        return vector<vector<int>>(res.begin(), res.end());
    }

    void backtracking(vector<int>& curr, vector<int>& candidates, set<vector<int>>& res, int target, int currNum, int idx) {
        if (currNum == target) {
            res.insert(curr);
            return;
        }

        if (currNum > target) return;

        for (int i = idx; i < candidates.size(); i ++) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue; 
            
            curr.push_back(candidates[i]);
            backtracking(curr, candidates, res, target, currNum + candidates[i], i + 1);
            curr.pop_back();
        }
    }
};