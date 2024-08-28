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
    vector<vector<int>> levelOrder(TreeNode* root) {

        
        vector<vector<int>> res;

        if (root == nullptr) return res;

        queue<TreeNode*> q;

        q.push(root);
        res.push_back({root->val});

        while (!q.empty()) {
            
            int curr_size = q.size();

            vector<int> level;

            for (int i = 0; i < curr_size; i ++) {

                TreeNode *node = q.front();
                q.pop();

                if (node == nullptr) break;

                if (node->left != nullptr) {
                    level.push_back(node->left->val);
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    level.push_back(node->right->val);
                    q.push(node->right);
                }
            }

            if (!level.empty())
                res.push_back(level);
            

        }

        return res;

    }
};
