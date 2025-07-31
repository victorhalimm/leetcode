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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        vector<int> res;

        q.push(root);
        res.push_back(root->val);

        while (!q.empty()) {
            int levelSize = q.size();
            TreeNode* endMost = NULL;

            for (int i = 0; i < levelSize; i ++) {
                TreeNode* curr = q.front();

                if (curr->left) {
                    q.push(curr->left);
                    endMost = curr->left;
                }

                if (curr->right) {
                    q.push(curr->right);
                    endMost = curr->right;
                }

                q.pop();
            }

            if (endMost) res.push_back(endMost->val);
        }

        return res;
    }
};