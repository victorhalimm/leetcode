#include <vector>
#include <set>
#include <iostream>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;

        int it_1 = 0, it_2 = 0;

        while (it_1 < nums1.size() && it_2 < nums2.size()) {

            if (nums1[it_1] < nums2[it_2]) {
                merged.push_back(nums1[it_1]);
                it_1 ++;
            } else {
                merged.push_back(nums2[it_2]);
                it_2 ++;
            }

        }

        while (it_1 < nums1.size()) {
            merged.push_back(nums1[it_1]);
            it_1 ++;
        }

        while (it_2 < nums2.size()) {
            merged.push_back(nums2[it_2]);
            it_2 ++;
        }

        int l = 0, r = merged.size() - 1;

        int mid = -1;

        if (l + (r - l) % 2 == 0) {
            mid = l + (r - l) / 2;
            return merged[mid];
        }

        
        l = l + (r - l) / 2;
        r = l + 1;

        return ((double) (merged[l] + merged[r]) / 2);

    }
};
