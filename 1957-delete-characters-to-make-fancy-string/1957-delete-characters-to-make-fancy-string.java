class Solution {
    public String makeFancyString(String s) {
        StringBuilder res = new StringBuilder();

        int freq = 0;
        char prev = '\0';

        for (char c : s.toCharArray()) {
            if (c != prev) {
                res.append(c);
                freq = 0;
                prev = c;
            }
            else if (freq >= 1) continue;
            else {
                res.append(c);
                freq ++;
            }
        }

        return res.toString();
    }
}