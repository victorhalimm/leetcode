#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:

    int findH(vector<int> &piles, int speed) {

        int h = 0;

        for (int pile : piles) {
            h += ceil((double) pile / speed);
        }

        return h;

    }


    int minEatingSpeed(vector<int>& piles, int h) {

        int maximal = *max_element(piles.begin(), piles.end());

        int l = 1, r = maximal;

        int res = maximal;

        while (l < r) {

            int mid = l + (r - l) / 2;
            int curr_h = findH(piles, mid);

            if (curr_h <= h) {
                res = min(res, mid);
                r = mid;
            }

            else {
                l = mid + 1;
            }


        }

        return res;

    }
};


// 3 6 7 11
// 8
// 4
