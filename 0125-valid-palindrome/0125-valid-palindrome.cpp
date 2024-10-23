class Solution {
public:
    bool isPalindrome(string s) {
        string clear = "";

        for (char c : s) {
            if (c >= 'A' && c <= 'Z') {
                clear += (c + ('a' - 'A'));
            }

            else if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                clear += (c);
            }
        }

        int l = 0, r = clear.size() - 1;


        while (l <= r) {
            if (clear[l] != clear[r]) {
                return false;
            }

            l ++; r --;
        }

        return true;
    }
};