class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> map;
        unordered_map<char, int> check;

        for (char c : s1) {
            map[c] ++;
        }

        int l = 0;
        for (int r = 0; r < s2.size(); r ++) {
            check[s2[r]] ++;

            if (r - l + 1 >= s1.size()) {
                if (check == map) return true;
                check[s2[l]] --;
                if (check[s2[l]] == 0) check.erase(s2[l]);
                l ++;
            }
        }

        return false;
    }
};