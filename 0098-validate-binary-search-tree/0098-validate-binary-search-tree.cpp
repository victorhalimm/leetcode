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

    bool dfs(TreeNode *root, long long left_min, long long right_max) {

        if (root == nullptr) 
            return true;

        if (root->left && root->left->val >= root->val)
            return false;

        if (root->right && root->right->val <= root->val)
            return false;

        if (root->left && root->left->val <= left_min)
            return false;

        if (root->right && root->right->val >= right_max)
            return false;


        return dfs(root->left, left_min, root->val) && dfs(root->right, root->val, right_max);

    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};