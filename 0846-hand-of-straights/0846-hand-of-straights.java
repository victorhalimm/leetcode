class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if (hand.length % groupSize != 0) return false;

        Map<Integer, Integer> map = new TreeMap<>();

        for (int num: hand) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        for (Map.Entry<Integer, Integer> entry: map.entrySet()) {
            int num = entry.getKey();

            while (map.get(num) > 0) {
                for (int i = 1; i < groupSize; i ++) {
                    if (map.getOrDefault(num + i, 0) == 0) return false;

                    int freq = map.get(num + i);
                    map.put(num + i, freq - 1);
                }

                map.put(num, map.get(num) - 1);
            }
        }

        return true;
    }
}

// 1 2 2 3 3 4 6 7 8 9
// 1 2 3 4   2 3 
// 1 2 3 7 8 9 