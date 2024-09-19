class Solution {
public:

    int calculate(int a, int b, char symbol) {
        if (symbol == '+') return a + b;
        if (symbol == '-') return a - b;
        return a * b;
    }

    vector<int> split(int l, int r, string& expression) {
        vector<int> res;

        for (int i = l; i < r; i ++) {
            char c = expression[i];

            if (c == '+' || c == '-' || c == '*') {
                vector<int> numsLeft = split(l, i - 1, expression);
                vector<int> numsRight = split(i + 1, r, expression);

                for (int numLeft : numsLeft) {
                    for (int numRight : numsRight) {
                        res.push_back(calculate(numLeft, numRight, c));
                    }
                } 
            }
        }

        if (res.empty()) {
            res.push_back(stoi(expression.substr(l, r - l + 1)));
        }

        return res;
    }

    vector<int> diffWaysToCompute(string expression) {
        return split(0, expression.size() - 1, expression);
    }
};