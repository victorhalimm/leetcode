class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> zeroRow, zeroCol;

        int m = matrix[0].size();
        int n = matrix.size();

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (matrix[i][j] == 0) {
                    zeroRow.insert(i);
                    zeroCol.insert(j);
                }
            }
        }

        for (auto row: zeroRow) {
            for (int i = 0; i < m; i ++) matrix[row][i] = 0;
        }

        for (auto col: zeroCol) {
            for (int i = 0; i < n; i ++) matrix[i][col] = 0;
        }
    }
};