class Solution {
public:
    int getLucky(string s, int k) {
        
        if (s.length() == 0 || k == 0) return 0;

        int total = 0;
        string num;
        
        for (int i = 0; i < k; i ++) {
            if (i == 0) {
                for (int j = 0; j < s.length(); j ++) {
                    int num = s[j] - 'a' + 1;

                    int first = num / 10;
                    int second = num % 10;

                    total += (first + second);
                }

            } else {
                int result = 0;

                for (char c : num) {
                    result += (c - '0');
                }

                total = result;
            }

            if (k > 1)
                num = to_string(total);

        }

        return total;

    }
};
