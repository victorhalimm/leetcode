class Solution {
public:
    // top-down memo approach
    int memo[46] = {0};

    int climbStairs(int n) {
        if (n <= 1) return memo[n] = 1;

        if (n == 2) return memo[n] = 2; 

        if (memo[n] != 0) return memo[n];

        return memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};