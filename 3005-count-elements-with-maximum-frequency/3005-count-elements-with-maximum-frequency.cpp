class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        if (nums.size() <= 0) return 0;
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for (int num: nums) {
            maxFreq = max(maxFreq, ++freq[num]);
        }

        unordered_map<int, int> elementsOfFreq;
        for (auto& [key, value] : freq) {
            elementsOfFreq[value] ++;
        }

        return maxFreq * elementsOfFreq[maxFreq];
    }
};