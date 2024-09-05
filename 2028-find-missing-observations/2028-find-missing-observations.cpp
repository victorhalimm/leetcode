#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        

        int diceCount = n + rolls.size();

        int currentSum = 0;

        for (int roll : rolls) {

            currentSum += roll;

        }

        int remainSum = mean * diceCount - currentSum;

        vector<int> missing;

        if (n * 6 < remainSum || remainSum < n) return missing;

        for (int i = 1; i <= 6; i ++) {

            if (remainSum / i > n) {
                continue;
            }

            if (i * n == remainSum) {

                for (int j = 0; j < n; j ++) {
                    missing.push_back(i);
                }

                break;
            }

            else {
                bool status = i * n < remainSum;
                int extra = status ? remainSum % i : i * n - remainSum;

                for (int j = 0; j < n; j ++) {
                    if (status) {
                        if (extra > 0 && i + extra <= 6) {
                            missing.push_back(i + extra);
                            extra = 0;
                        }

                        else if (extra > 0) {
                            int added = 6 - i;

                            missing.push_back(6);
                            extra -= added;
                        }

                        else missing.push_back(i);
                    } else {
                        if (extra > 0 && i - extra >= 1) {
                            missing.push_back(i - extra);
                            extra = 0;
                        }

                        else if (extra > 0) {
                            int decreased = i - 1;

                            missing.push_back(1);
                            extra -= decreased;
                        }
                        else missing.push_back(i);
                    }
                }
                break;
            }
        }

        return missing;
    }
};




