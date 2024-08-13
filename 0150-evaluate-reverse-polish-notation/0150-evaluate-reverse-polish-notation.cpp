
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:

    int calculate(int a, int b, string symbol) {
        if (symbol == "+") return a + b;
        if (symbol == "*") return a * b;
        if (symbol == "-") return a - b;
        return a / b;
    }

    int evalRPN(vector<string>& tokens) {
        
        stack<int> nums;

        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {

                int a = nums.top(); nums.pop();
                int b = nums.top(); nums.pop();

                int res = calculate(b, a, token);

                nums.push(res);
            }

            else {
                nums.push(stoi(token));
            }
        }

        return nums.top();

    }
};