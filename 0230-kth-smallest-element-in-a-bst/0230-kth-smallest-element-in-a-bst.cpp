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

    int i = 0;
    int res = -1;

    void dfs(TreeNode *root, int k) {
        if (root == nullptr)
            return;

        dfs(root->left, k);

        if (i == k - 1)
            res = root->val;
        
        i ++;

        dfs(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        
        dfs(root, k);
        
        return res;
    }
};