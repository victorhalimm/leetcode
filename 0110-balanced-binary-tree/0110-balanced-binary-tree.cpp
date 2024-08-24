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

    int dfs(TreeNode *root) {

        if (root == nullptr) return 0;

        int left_h = dfs(root->left);
        int right_h = dfs(root->right);

        return max(left_h, right_h) + 1;
    }

    bool isBalanced(TreeNode* root) {

        if (root == nullptr) return true;

        if (isBalanced(root->left) == false || isBalanced(root->right) == false) return false;

        int left_h = dfs(root->left);
        int right_h = dfs(root->right);

        int bf = left_h - right_h;
        
        if (bf > 1 || bf < -1) return false;

        return true;
    }
};