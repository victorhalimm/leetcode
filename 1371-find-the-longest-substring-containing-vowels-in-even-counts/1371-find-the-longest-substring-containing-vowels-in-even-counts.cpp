class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char, int> bit {
            {'a' , 1},
            {'e' , 2},
            {'i', 4},
            {'o', 8},
            {'u', 16}
        };

        vector<int> prefix(32, -1);

        int res = 0, currMask = 0;

        for (int i = 0; i < s.size(); i ++) {
            if (bit[s[i]] != 0) currMask = currMask ^ bit[s[i]];

            if (prefix[currMask] != -1 || currMask == 0) {
                int currRes = i - prefix[currMask];
                res = max(res, currRes);
            }
            else {
                prefix[currMask] = i;
            }
        }

        return res;
    }
};
