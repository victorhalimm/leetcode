class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int i = 0;
        while (i < gas.size()) {
            
            int currIdx = i;
            int remain = 0;

            do {
                
                remain = remain + gas[currIdx] - cost[currIdx];

                if (remain < 0) break;

                currIdx = (currIdx + 1) % len;
            } while (currIdx != i);


            if (remain >= 0) return i;
            if (currIdx < i) break;

            i = currIdx + 1;
        }

        return -1;
    }


};