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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode *> q;
        q.push(root);
        
        root->val = 0;

        long long lastChildSum = 0;

        while (!q.empty()) {
            int len = q.size();
            long long childSum = 0;
            queue<TreeNode *> temp;

            for (int i = 0; i < len; i ++) {
                if (q.front()->left) childSum += q.front()->left->val;
                if (q.front()->right) childSum += q.front()->right->val;

                temp.push(q.front());
                q.pop();
            }

            for (int i = 0; i < len; i ++) {
                long long siblingSum = 0;

                if (temp.front()->left) siblingSum += temp.front()->left->val; 
                if (temp.front()->right) siblingSum += temp.front()->right->val;

                if (temp.front()->left) {
                    temp.front()->left->val = childSum - siblingSum;
                    q.push(temp.front()->left);
                }

                if (temp.front()->right) {
                    temp.front()->right->val = childSum - siblingSum;
                    q.push(temp.front()->right);
                }

                temp.pop();
            }   
        }

        return root;
    }
};
