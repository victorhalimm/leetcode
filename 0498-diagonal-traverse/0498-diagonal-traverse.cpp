class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return {};

        int m = mat.size();
        int n = mat[0].size();

        vector<int> res;

        int total = m * n;

        int i = 0, j = 0;
        bool reverse = false;

        while (res.size() < total) {
            res.push_back(mat[i][j]);

            if (res.size() >= total) break;

            if (!reverse) {
                if (i > 0 && j < n - 1) {
                    i --;
                    j ++;
                } else {
                    reverse = !reverse;
                    if (j < n - 1) j ++;
                    else i ++;
                }
            } else {
                if (i < m - 1 && j > 0) {
                    i ++;
                    j --;
                } else {
                    reverse = !reverse;
                    if (i < m - 1) i ++;
                    else j ++;
                }
            }
        }

        return res;
    }
};