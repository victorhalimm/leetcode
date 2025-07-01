class Solution {
public:
    int possibleStringCount(string word) {
        if (word.empty()) return 0;

        char prev = word[0];

        int total = 1;

        for (int i = 1; i < word.length(); i ++) {
            if (word[i] == prev) total ++;
            else prev = word[i];
        }

        return total;
    }
};