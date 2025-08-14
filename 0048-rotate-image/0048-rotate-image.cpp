class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix.size(), vector<int>(matrix.size(), -1));

        int n = matrix.size();

        for (int i = 0; i < n; i ++) {
            for (int j = n - 1; j >= 0; j --) {
                res[i][n - j - 1] = matrix[j][i];
            }
        }

        matrix = res;
    }
};