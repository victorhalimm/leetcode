class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
                continue;
            }

            if (stack.empty()) return false;

            if (c == ')' && stack.top() == '(') {
                stack.pop();
                continue;
            }
            if (c == ']' && stack.top() == '[') {
                stack.pop();
                continue;
            }
            if (c == '}' && stack.top() == '{') {
                stack.pop();
                continue;
            }

            return false;
            
        }

        return stack.empty();
    }
};