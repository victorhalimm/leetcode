class Solution {
public:
    int lengthOfLastWord(string s) {
        
        bool foundLetter = false;
        int res = 0;

        for (int i = s.size() - 1; i >= 0; i --) {
            if (s[i] != ' ') {
                foundLetter = true;
                res ++;
            }

            else if (foundLetter) return res;
        }

        return res;
    }
};