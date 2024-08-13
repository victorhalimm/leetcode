
#include <unordered_map> 
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash_map;
        int sol = 0;
        int start = 0; 

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (hash_map.find(c) != hash_map.end() && hash_map[c] >= start) {
                start = hash_map[c] + 1;
            }

            hash_map[c] = i;

            sol = max(sol, i - start + 1);
        }

        return sol;
    }
};