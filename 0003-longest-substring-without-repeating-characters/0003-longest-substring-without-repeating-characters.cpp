class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int l = 0, longest = 0;
        for (int r = 0; r < s.size(); r ++) {
            while (set.count(s[r])) {
                set.erase(s[l ++]);
            }

            set.insert(s[r]);
            longest = max(longest, r - l + 1);
        }

        return longest;
    }
};