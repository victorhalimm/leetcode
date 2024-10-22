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
    long long kthLargestLevelSum(TreeNode* root, int k) {

        if (!root) return 0;

        priority_queue<long long> pq;

        queue<TreeNode *> q;
        q.push(root);

        int levelCount = 0;

        while (!q.empty()) {
            levelCount ++;
            int len = q.size();

            long long levelSum = 0;
            for (int i = 0; i < len; i ++) {
                TreeNode *curr = q.front();

                levelSum += curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);

                q.pop();
            }

            pq.push(levelSum);
        }

        if (k > levelCount) return -1; 

        while (k > 1) {
            pq.pop();
            k --;
        }

        return pq.top();
    }
};