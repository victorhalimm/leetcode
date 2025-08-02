class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        priority_queue<pair<int, char>> pq;
        string res = "";

        for (char c: s) {
            freqMap[c] ++;
        }

        for (auto& [letter, freq]: freqMap) {
            pq.push({freq, letter});
        }

        while (!pq.empty()) {
            auto [freq, letter] = pq.top(); pq.pop();

            for (int i = 0; i < freq; i ++) res += letter;
        }

        return res;
    }
};