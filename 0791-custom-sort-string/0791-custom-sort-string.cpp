class Solution {
public:
    string customSortString(string order, string s) {
        // cbag ighbcc
        unordered_map<char, int> freqOfS;

        string res = "";

        for (char c : s) {
            freqOfS[c] ++;
        }

        for (char c : order) {
            if (freqOfS[c]) {
                res.append(freqOfS[c], c);
                freqOfS.erase(c);
            }
        }

        for (auto& entry: freqOfS) {
            res.append(entry.second, entry.first);
        }


        return res;
    }
};