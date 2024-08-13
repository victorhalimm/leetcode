
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int len = nums.size();

        unordered_map<int, int> freq;
        unordered_map<int, vector<int>> count;

        vector<int> unique;

        for (int num : nums ) {
            if (freq[num] == 0) 
                unique.push_back(num);

            freq[num] ++;
        }

        for (int num : unique) {
            count[freq[num]].push_back(num);
        }

        int remain_num = k;
        vector<int> res;

        for (int i = len; i > 0; i --) {

            if (remain_num <= 0) 
                return res;

            if (!count[i].empty() && remain_num > 0) {
                
                for (int num : count[i]) {

                    if (remain_num <= 0) 
                        return res;

                    res.push_back(num);
                    remain_num --;

                }

            }


        }

        return res;
        

    }
};
