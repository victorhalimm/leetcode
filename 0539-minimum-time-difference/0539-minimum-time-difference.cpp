class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if (timePoints.size() < 2) return -1;

        // Minute maximum in a day is 1440
        int res = 1440;
        vector<int> minutes;

        for (const auto& time : timePoints) {
            int h, m;
            sscanf(time.c_str(), "%d:%d", &h, &m);
            minutes.push_back(h * 60 + m);
        }

        sort(minutes.begin(), minutes.end());

        for (int i = 1; i < minutes.size(); i++) {
            res = min(res, minutes[i] - minutes[i - 1]);
        }

        // Ini compare ujungnya soalnya ada kemungkinan jadi yg paling deket jg
        res = min(res, 1440 - (minutes.back() - minutes.front()));

        return res;
    }
};