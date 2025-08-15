class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y, int m, int n) {
        if (x >= n || y >= m || x < 0 || y < 0 || grid[y][x] == '0') return;

        grid[y][x] = '0';

        dfs(grid, x + 1, y, m, n);
        dfs(grid, x, y + 1, m, n);
        dfs(grid, x - 1, y, m, n);
        dfs(grid, x, y - 1, m, n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i ++) {
            vector<char> gridX = grid[i];

            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == '1') {
                    res ++;
                    dfs(grid, j, i, m, n);
                }
            }
        }

        return res;
    }
};