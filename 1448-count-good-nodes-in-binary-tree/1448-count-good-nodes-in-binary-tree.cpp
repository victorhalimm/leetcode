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

    int good = 0;

    void dfs(TreeNode *root, int max_val) {

        if (root == nullptr)
            return;

        if (max_val <= root->val) {
            good ++;
            max_val = root->val;
        }

        dfs(root->left, max_val);
        dfs(root->right, max_val);
    }

    int goodNodes(TreeNode* root) {
        
        if (root == nullptr) return 0;

        dfs(root, root->val);

        return good;

    }
};