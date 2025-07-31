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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        return dfs(root, 0, targetSum);


    }

    bool dfs(TreeNode* root, int curr, int targetSum) {
        if (!root) return false;

        curr = root->val + curr;

        if (!root->left && !root->right) return targetSum == curr;

        bool left = dfs(root->left, curr, targetSum);
        bool right = dfs(root->right, curr, targetSum);

        return left || right;
    }


};