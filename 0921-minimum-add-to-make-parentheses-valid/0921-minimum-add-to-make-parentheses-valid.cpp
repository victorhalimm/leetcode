class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> res;

        if (s.empty()) return res.size();

        for (int i = 0; i < s.size(); i ++) {

            if (!res.empty() &&  res.top() == '(' && s[i] == ')') {
                res.pop();
            } else {
                res.push(s[i]);
            }
        }

        return res.size();
    }
};