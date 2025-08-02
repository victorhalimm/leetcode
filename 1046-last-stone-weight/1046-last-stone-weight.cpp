class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (int stone: stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();

            int res = first - second;
            if (res) pq.push(res);
        }

        return pq.empty() ? 0 : pq.top();
    }
};