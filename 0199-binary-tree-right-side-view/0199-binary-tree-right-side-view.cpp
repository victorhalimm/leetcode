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

    void bfs(TreeNode *root, vector<int>& res) {

        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i ++) {

                if (i == size - 1) 
                    res.push_back(q.front()->val);
                
                TreeNode *curr = q.front();
                q.pop();

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }

    }

    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> res;

        if (root == nullptr) return res;

        bfs(root, res);

        return res;
    }
};