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

    bool isSameTree(TreeNode* root1, TreeNode* root2) {

        if (root1 == nullptr && root2 == nullptr)
            return true;

        if (root1 == nullptr || root2 == nullptr) 
            return false;

        if (isSameTree(root1->left, root2->left) == false || isSameTree(root1->right, root2->right) == false)
            return false;

        if (root1->val != root2->val)
            return false;


        return true;

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (root == nullptr && subRoot == nullptr)
            return true;
        
        if (subRoot == nullptr)
            return true;

        if (isSameTree(root, subRoot))
            return true;

        if (root->left && isSubtree(root->left, subRoot) == true || root->right &&isSubtree(root->right, subRoot) == true)
            return true;

        return false;
    }
};