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
    int maxDiameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);

        return maxDiameter;
    }

    int dfs(TreeNode* node) {
        if (!node) return 0;
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        maxDiameter = max(maxDiameter, left + right);

        return max(left, right) + 1;
    }
};