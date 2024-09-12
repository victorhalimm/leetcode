class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int map[26] = {0};
        int counter = 0;

        for (char c : allowed) {
            map[c - 'a'] = 1;
        }

        for (string& word : words) {
            bool valid = true;

            for (char c : word) {
                if (map[c - 'a'] == 0) {
                    valid = false;
                    break;
                }
            }

            if (valid) counter ++;
        }

        return counter;

    }
};