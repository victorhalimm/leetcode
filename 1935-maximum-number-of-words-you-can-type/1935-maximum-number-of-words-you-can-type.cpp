class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int alphabet[26] = {0};
        bool possible = true;

        int res = 0;

        for (char c: brokenLetters) {
            alphabet[c - 'a'] = 1;
        }

        for (char c : text) {
            if (c == ' ') {
                if (possible) res ++;
                possible = true;
            }

            if (c >= 'a' && c <= 'z' && alphabet[c - 'a']) possible = false;
        }

        if (possible) res ++;


        return res;
    }
};