class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreatMap;
        vector<int> res;
        stack<int> stack;

        for (int i = nums2.size() - 1; i >= 0; i --) {
            while (!stack.empty() && stack.top() <= nums2[i]) {
                stack.pop();
            }

            if (!stack.empty()) nextGreatMap[nums2[i]] = stack.top();

            stack.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i ++) {
            if (nextGreatMap[nums1[i]]) res.push_back(nextGreatMap[nums1[i]]);
            else res.push_back(-1);
        }

        return res;
    }
};