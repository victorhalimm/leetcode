class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        if (numBottles < numExchange) return numBottles;

        int emptyBottles = 0;
        int res = 0;

        while (emptyBottles + numBottles >= numExchange) {
            res += numBottles;
            emptyBottles += numBottles;

            if (emptyBottles < numExchange) return res;

            numBottles = 1;
            emptyBottles -= numExchange;

            numExchange ++;
        }

        return res + numBottles;
    }
};