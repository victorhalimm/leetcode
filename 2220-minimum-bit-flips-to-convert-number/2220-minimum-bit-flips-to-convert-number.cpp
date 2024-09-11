class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int min = 0, target = start ^ goal;

        while (target) {
            target = target & (target - 1);
            min ++;
        }

        return min;
    }
};