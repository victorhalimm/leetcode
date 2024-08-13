#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
public:


    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, int>> car;
        int count = 0;

        int len = position.size();

        for (int i = 0; i < len; i ++) {
            car.push_back({position[i], speed[i]});
        }

        sort(car.begin(), car.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.first > b.first;
        });

        stack<double> active_fleet;

        for (int i = 0; i < car.size(); i ++) {

            double round = (double) (target - car[i].first) / car[i].second;

            if (active_fleet.empty() || active_fleet.top() < round) {
                active_fleet.push(round);
            }

        }

        return active_fleet.size();



    }
};

// 10 8 0 5 3
// 12 12 1 6 6
// 