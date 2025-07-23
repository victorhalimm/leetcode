class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        // 1 2 3 4
        // 5 6 7 8
        // 9 10 11 12
        // 13 14 15 16
        // 17 18 19 20
        // 21 22 23 24
        int n = matrix.length;
        int m = matrix[0].length;
        int total = m * n;

        List<Integer> res = new ArrayList<>();

        int loop = 0;
        int count = 0;
        
        while (count < total) {
            int startHori = loop;
            int startVertical = loop;

            while (startHori < m) {
                if (count >= total) break;
                res.add(matrix[loop][startHori]);
                startHori ++;
                count ++;
            }

            startHori --;
            startVertical ++;

            while (startVertical < n) {
                if (count >= total) break;
                res.add(matrix[startVertical][startHori]);
                startVertical ++;
                count ++;
            }

            startVertical --;
            startHori --;

            while (startHori > loop) {
                if (count >= total) break;
                res.add(matrix[startVertical][startHori]);
                startHori --;
                count ++;
            }

            while (startVertical > loop) {
                if (count >= total) break;
                res.add(matrix[startVertical][startHori]);
                startVertical --;
                count ++;
            }

            if (count >= total) break;

            loop ++;
            m --; n --;
        }

        return res;
    }
}