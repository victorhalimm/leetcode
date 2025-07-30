class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<pair<int,int>> stk;

        for (int i = 0; i < temperatures.size(); i ++) {
            while (!stk.empty() && stk.top().first < temperatures[i]) {
                res[stk.top().second] = i -  stk.top().second;
                stk.pop();
            }

            stk.push({temperatures[i], i});
        }

        return res;
    }
};