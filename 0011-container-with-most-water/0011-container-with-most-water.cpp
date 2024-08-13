#include <vector>

using namespace std;

class Solution {
public:

    int min(int a, int b) {
        return a < b ? a : b;
    }

    int max(int a, int b) {
        return a > b ? a : b;
    }

    int maxArea(vector<int>& height) {
        
        int max_area = 0;

        int l = 0;
        int r = height.size() - 1;

        while (l < r) {

            int area = min(height[l], height[r]) * (r - l);

            max_area = max(max_area, area);

            if (height[l] < height[r]) l ++;
            else r --;
        }

        return max_area;

    }
};