#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:


    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            // Hash the first element
            size_t hash1 = hash<T1>{}(p.first);
            // Hash the second element
            size_t hash2 = hash<T2>{}(p.second);
            // Combine the two hash values
            return hash1
               ^ (hash2 + 0x9e3779b9 + (hash1 << 6)
                  + (hash1 >> 2));
        }
    };

    bool checkValidIndex(const vector<int>& idx, int iter) {
        auto it = lower_bound(idx.begin(), idx.end(), iter);
        return it != idx.end();
    }


    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, vector<int>> h_map;

        for (int i = 0; i < nums.size(); i ++) {
            h_map[nums[i]].push_back(i + 1);
        }

        vector<vector<int>> res;
        unordered_set<pair<int, int>, hash_pair> combination;


        for (int i = 0; i < nums.size(); i ++) {

            int num = nums[i];
            int target_1 = -1 * num;

            for (int j = i + 1; j < nums.size(); j ++) {
                int target_2 = target_1 - nums[j];


                if (h_map.find(target_2) != h_map.end() && checkValidIndex(h_map[target_2], j + 2)) {

                    if (combination.find({num, nums[j]}) == combination.end()) {
                        vector<int> put = {num, nums[j], target_2};
                        res.push_back(put);

                        combination.insert({num, nums[j]});
                        combination.insert({num, target_2});
                        combination.insert({nums[j], target_2});
                        combination.insert({nums[j], num});
                        combination.insert({target_2, num});
                        combination.insert({target_2, nums[j]});
                    } 
                }

            }

        }

        return res;

    }
};
// [-1,0,1,2,-1,-4]