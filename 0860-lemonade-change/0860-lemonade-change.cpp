class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (int num: bills) {
            if (num == 5) five ++;
            else if (num == 10) {
                five --;
                ten ++;
            }
            else {
                if (ten > 0) {
                    ten --;
                    five --;
                }
                else five -= 3;
            }

            if (five < 0 || ten < 0) return false;
        }

        return true;
    }
};