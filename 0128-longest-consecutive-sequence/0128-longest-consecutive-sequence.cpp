#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:

    int max(int a, int b) {
        return a > b ? a : b;
    }

    int longestConsecutive(vector<int>& nums) {
        

        unordered_set<int> hash_set;
        unordered_set<int> curr_set;

        int longest = 0;

        for (int num : nums) {
            hash_set.insert(num);
        }

        for (int num : nums) {

            if (hash_set.find(num - 1) == hash_set.end()) {

                int streak = 1;
                int curr = num;

                while (hash_set.find(curr + 1) != hash_set.end()) {
                    streak ++;
                    curr ++;
                }

                longest = max(streak, longest);

            }

        }

        return longest;
    }
};

// 102 1 3 2 101 5 4 103