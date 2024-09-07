class Solution {
public:
    bool dfsFromNode(TreeNode* root, vector<int>& nums, int index) {
        if (root == nullptr) return false;

        if (root->val != nums[index]) return false;

        if (index == nums.size() - 1) return true;

        return dfsFromNode(root->left, nums, index + 1) || dfsFromNode(root->right, nums, index + 1);
    }

    bool dfs(TreeNode* root, vector<int>& nums) {
        if (root == nullptr) return false;

        if (dfsFromNode(root, nums, 0)) return true;

        return dfs(root->left, nums) || dfs(root->right, nums);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int> nums;
        ListNode* curr = head;

        while (curr) {
            nums.push_back(curr->val);
            curr = curr->next;
        }

        return dfs(root, nums);
    }
};
