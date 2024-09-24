class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        
        if (arr1.empty() || arr2.empty()) return 0;

        unordered_set<int> arr1Set;

        for (int num : arr1) {
            while (arr1Set.count(num) == 0 && num > 0) {
                arr1Set.insert(num);
                num /= 10;
            }
        }

        int res = 0;

        for (int num : arr2) {

            int copy = num;
            int len = 0;

            int divisor = 1;

            while (copy / 10 > 0) {
                divisor *= 10;
                copy /= 10;
            }

            int target = num / divisor;

            while (divisor > 0) {

                if (arr1Set.find(target) != arr1Set.end()) len ++;

                divisor /= 10;

                if (divisor > 0) target = num / divisor;
            }

            res = max(res, len);
        }

        return res;
    }
};