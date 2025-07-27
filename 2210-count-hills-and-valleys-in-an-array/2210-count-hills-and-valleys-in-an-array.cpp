class Solution {
public:
    int countHillValley(vector<int>& nums) {
        if (nums.size() <= 2) return 0;

        int count = 0;
        int i = 1;

        vector<int> dupsRemoved;
        dupsRemoved.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] != nums[i-1] ) dupsRemoved.push_back(nums[i]);
        }

        while (i < dupsRemoved.size() - 1) {
            if (dupsRemoved[i] < dupsRemoved[i + 1] && dupsRemoved[i] < dupsRemoved[i - 1]) count ++ ;
            if (dupsRemoved[i] > dupsRemoved[i + 1] && dupsRemoved[i] > dupsRemoved[i - 1]) count ++ ;

            i ++;
        }

        return count;
    }
};