class Solution {
public:
    string countAndSay(int n) {
        if (n <= 1) return "1";

        string count = countAndSay(n - 1);
        string say = "";

        int freq = 1;
        for (int i = 0; i < count.size(); i ++) {
            if (i + 1 < count.size() && count[i] == count[i + 1]) {
                freq++;
            } else {
                say += to_string(freq);
                say += count[i];
                freq = 1;
            }
        }

        return say;
    }
};