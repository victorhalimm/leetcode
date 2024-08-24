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

    int maximum = 0;

    int dfs(TreeNode *root) {
        if (root == nullptr) return 0;

        int left_h = dfs(root->left);
        int right_h = dfs(root->right);

        maximum = max(maximum, left_h + right_h);

        return max(left_h, right_h) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        
        int height = dfs(root);

        return maximum;
    }
};