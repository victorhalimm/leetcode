#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        if (chalk.empty())
            return -1;

        long long sum = 0;

        for (int num : chalk) {
            sum += num;
        }

        if (sum == 0)
            return -1;

        long long remain = k % sum;

        for (int i = 0; i < chalk.size(); i ++) {
            if (remain < chalk[i])
                return i;
            
            remain -= chalk[i];
        }

        return -1;
    }
};

