class Solution {
    public int maximumGain(String s, int x, int y) {
        // baa
        // 4 8
        // 8 
        Deque<Character> stack = new ArrayDeque<>();
        int res = 0;

        int high = Math.max(x, y);
        int low = Math.min(x, y);

        boolean preferAB = x >= y;
        String highSubstring = preferAB ? "ab" : "ba";
        String lowSubstring = preferAB ? "ba" : "ab";

        for (char c : s.toCharArray()) {
            
            if (!stack.isEmpty() && stack.peek() == highSubstring.charAt(0) && c == highSubstring.charAt(1)) {
                res += high;
                stack.pop();
                continue;
            }

            stack.push(c);
        }

        Deque<Character> residue = new ArrayDeque<>();
        while (!stack.isEmpty()) {
            char c = stack.pop();

            if (!residue.isEmpty() && residue.peek() == lowSubstring.charAt(1) && c == lowSubstring.charAt(0)) {
                res += low;
                residue.pop();
                continue;
            }

            residue.push(c);
        }

        return res;
    }
}