class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        
        int length = gas.length;
        int i = 0;
        while (i < length) {
            if (gas[i] < cost[i]) {
                i ++;
            }

            int remain = 0;
            boolean possible = true;

            int steps = 0;
            int j = i;

            while (steps < length) {
                remain += gas[j] - cost[j];

                if (remain < 0) {
                    possible = false;
                    break;
                }

                j = (j + 1) % length;
                steps++;
            }

            if (possible) return i;

            i += steps;
        }

        return -1;
    }
}