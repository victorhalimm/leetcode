#include <vector>
#include <stdio.h>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();

        int l_col = 0, r_col = m - 1;
        int col_i = -1;

        while (l_col <= r_col) {

            int mid = l_col + (r_col - l_col) / 2;

            if (matrix[mid][0] == target || matrix[mid][n - 1] == target) return true;

            else if (target < matrix[mid][0]) {
                printf("Smaller %d %d\n", l_col, r_col);
                if (mid > 0 && target > matrix[mid - 1][0]) {
                    col_i = mid - 1;
                    break;
                }
                
                r_col = mid - 1; 
            }
            
            else {
                printf("Larger %d %d\n", l_col, r_col);
                if ((mid < m - 1 && target < matrix[mid + 1][0]) || l_col == r_col) {
                    col_i = mid;
                    break;
                }

                l_col = mid + 1;

            }
        }

        if (col_i == -1) return false;

        vector<int> row = matrix[col_i];

        int l = 0, r = row.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (row[mid] == target) return true;

            else if (row[mid] < target) l = mid + 1;

            else r = mid - 1;

        }

        return false;
    }
};