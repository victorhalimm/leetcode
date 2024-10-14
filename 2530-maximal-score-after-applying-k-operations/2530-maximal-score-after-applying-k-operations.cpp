class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        if (nums.empty()) return 0;

        priority_queue<int> pq;

        for (int num : nums) {
            pq.push(num);
        }

        long long score = 0;

        for (int i = 0; i < k; i ++) {
            long long val = pq.top();

            score += val;
            val = ceil((double) val / 3);
            pq.pop();
            pq.push(val);
        }

        return score;

    }
};