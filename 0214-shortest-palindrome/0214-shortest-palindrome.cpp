class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int base = 29; 
        int mod = 1e9 + 7;

        long long forwardHash = 0;
        long long reverseHash = 0;
        long long basePow = 1;

        int bestPrefixLen = 0;

        for (int i = 0; i < n; ++i) {
            forwardHash = (forwardHash * base + (s[i] - 'a' + 1)) % mod;
            reverseHash = (reverseHash + (s[i] - 'a' + 1) * basePow) % mod;

            if (forwardHash == reverseHash) {
                bestPrefixLen = i + 1;
            }

            basePow = (basePow * base) % mod;
        }

        string suffix = s.substr(bestPrefixLen);
        reverse(suffix.begin(), suffix.end());

        return suffix + s;
    }
};