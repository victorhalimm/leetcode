class Solution {
public:
    int minLength(string s) {
        
        stack<char> stringStack;

        for (int i = 0; i < s.length(); i ++) {

            char current = s[i];

            if (stringStack.empty()) {
                stringStack.push(current);
                continue;
            }

            if (stringStack.top() == 'A' && current == 'B') {
                stringStack.pop();
            }

            else if (stringStack.top() == 'C' && current == 'D') {
                stringStack.pop();
            }

            else {
                stringStack.push(current);
            }
        }

        return stringStack.size();
    }
};