#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> res(temperatures.size(), 0);

        stack<int> idx;

        for (int i = 0; i < temperatures.size(); i ++) {
    
            while (!idx.empty() && temperatures[idx.top()] < temperatures[i]) {
                res[idx.top()] = i - idx.top();
                idx.pop(); 
            }

            idx.push(i);
        }

        return res;

    }
};