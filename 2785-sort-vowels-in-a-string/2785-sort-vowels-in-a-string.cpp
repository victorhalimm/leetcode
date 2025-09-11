class Solution {
public:
    bool isVowel(char c) {
        if (c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O' || c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') return true;

        return false;
    }
    string sortVowels(string s) {
        vector<char> vowels;

        for (char c: s) {
            if (isVowel(c)) vowels.push_back(c);
        }

        sort(vowels.begin(), vowels.end());

        int j = 0;
        for (int i = 0; i < s.size(); i ++) {
            if (isVowel(s[i])) {
                s[i] = vowels[j ++];
            }
        }

        return s;
    }
};