#include <bits/stdc++.h>

class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0) return false;

        int divisor = 1;

        while (x / divisor >= 10) 
            divisor *= 10;

        while (x > 0) {
            int lead = x / divisor;
            int trailing = x % 10;

            if (lead != trailing) return false;

            x = (x % divisor) / 10;
            divisor = divisor / 100;
        }

        return true;
    }
};