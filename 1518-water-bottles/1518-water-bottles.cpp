class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if (numExchange > numBottles) return numBottles;

        int res = numBottles;

        while (numBottles > 0) {
            if (numBottles < numExchange) break;

            int remain = numBottles % numExchange;
            numBottles = numBottles / numExchange;

            res += numBottles;
            numBottles += remain;
        } 

        return res;
    }
};