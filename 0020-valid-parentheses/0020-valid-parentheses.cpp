class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stack;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.empty()) return false;

                if (stack.top() != '(' && c == ')') {
                    return false;
                }

                else if (stack.top() != '[' && c == ']') {
                    return false;
                }

                else if (stack.top() != '{' && c == '}') {
                    return false;
                }

                stack.pop();
            }

        }


        return stack.empty();

    }
};