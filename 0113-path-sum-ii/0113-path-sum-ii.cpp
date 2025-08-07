/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        vector<vector<int>> res;
        vector<int> curr;

        if (!root) return res;
        
        curr.push_back(root->val);
        backtrack(res, curr, root, targetSum - root->val);

        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& curr, TreeNode* root, int targetSum) {
        if (!root) return;
        
        if (!root->left && !root->right && targetSum == 0) {
            res.push_back(curr);
            return;
        }

        if (root->left) {
            curr.push_back(root->left->val);
            backtrack(res, curr, root->left, targetSum - root->left->val);
            curr.pop_back();
        }

        if (root->right) {
            curr.push_back(root->right->val);
            backtrack(res, curr, root->right, targetSum - root->right->val);
            curr.pop_back();
        }
    }
};