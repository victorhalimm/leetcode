#include <vector>


using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int buy_i = -1;
        int sell_i = -1;

        int best = 0;
        
        for (int i = 0; i < prices.size(); i ++) {

            if (buy_i == -1 || prices[buy_i] > prices[i]) {

                if (sell_i != -1 && best < prices[sell_i] - prices[buy_i]) {
                    best = prices[sell_i] - prices[buy_i];
                }

                buy_i = i;
                sell_i = i + 1;
            }

            else if (prices[i] - prices[buy_i] > best){

                best = prices[i] - prices[buy_i];
                sell_i = i;
            }

        }

        return best;

    }
};

// 7,1,5,3,6,4
//