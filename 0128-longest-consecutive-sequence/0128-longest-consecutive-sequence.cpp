class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;

        for (int num: nums) {
            set.insert(num);
        }

        int longest = 0;
        for (int num: set) {
            if (!set.count(num - 1)) {
                int next = num, curr = 0;
                while (set.count(next)) {
                    longest = max(longest, ++curr);
                    next ++;
                }
            }
        }

        return longest;
    }
};