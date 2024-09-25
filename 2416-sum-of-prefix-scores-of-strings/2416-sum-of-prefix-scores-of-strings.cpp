class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<long long, int> prefixCount;

        long long mod = 1e15 + 7;

        for (const string& word : words) {
            long long hashValue = 0;
            for (char c : word) {
                hashValue = (hashValue * 97 + c) % mod;
                prefixCount[hashValue]++;
            }
        }

        vector<int> res;
        for (const string& word : words) {
            long long hashValue = 0;
            int score = 0;
            for (char c : word) {
                hashValue = (hashValue * 97 + c) % mod;
                score += prefixCount[hashValue];
            }
            res.push_back(score);
        }

        return res;
    }
};