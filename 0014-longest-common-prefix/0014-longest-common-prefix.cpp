#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string first = strs[0];

        for (int i = 0; i < first.length(); i++) {
            char c = first[i];

            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != c) {
                    return first.substr(0, i);
                }
            }
        }

        return first;
    }
};
