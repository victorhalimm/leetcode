class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if (needle.length() > haystack.length()) return -1;

        for (int i = 0; i < haystack.length(); i ++) {

            bool valid = true;

            for (int j = 0; j < needle.length(); j ++) {
                if (needle[j] != haystack[i + j]) {
                    valid = false;
                    break;
                }
            }

            if (valid)
                return i;
        }

        return -1;
    }
};