class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        vector<vector<int>> res;

        if (original.size() != m * n) return res;

        for (int i = 0; i < m ; i ++) {

            int start = i * n;
            int end = (i + 1) * n;

            vector<int> row;
            
            for (int j = start; j < end; j ++) {

                row.push_back(original[j]);
            }

            res.push_back(row);
        }

        return res;
    }
};