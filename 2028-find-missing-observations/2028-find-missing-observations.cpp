class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int totalMissing, total = 0, quantity = n + rolls.size();
        vector<int> vect;

        for(int roll : rolls) total += roll;
        totalMissing = (quantity * mean) - total;

        int average = totalMissing / n;
        if(n * 6 < totalMissing || average == 0) return vect;

        while(totalMissing > 0) {
            average = totalMissing/(n-vect.size());
            if(totalMissing >= average && vect.size() < n - 1) {
                vect.push_back(average);
                totalMissing -= average;
            } else {
                vect.push_back(totalMissing);
                totalMissing -= totalMissing;
            }
        }

        return vect;
    }
};