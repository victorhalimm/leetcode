class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.size() <= 0) return -1;

        int n = grid.size();
        int m = grid[0].size();

        int healthy_count = 0;        
        queue<pair<int, int>> rotten_orange_coords;
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (grid[i][j] == 2) {
                    rotten_orange_coords.push({i, j});
                }

                if (grid[i][j] == 1) healthy_count ++;
            }
        }

        int duration = 0;
        while (!rotten_orange_coords.empty()) {
            int curr_oranges = rotten_orange_coords.size();
            bool can_infect = false;

            for (int i = 0; i < curr_oranges; i ++) {
                pair<int, int> curr = rotten_orange_coords.front(); rotten_orange_coords.pop();
                if (curr.first + 1 < n && grid[curr.first + 1][curr.second] == 1) {
                    grid[curr.first + 1][curr.second] = 2;
                    rotten_orange_coords.push({curr.first + 1, curr.second});
                    healthy_count --;
                    can_infect = true;
                }

                if (curr.second + 1 < m && grid[curr.first][curr.second + 1] == 1) {
                    grid[curr.first][curr.second + 1] = 2;
                    rotten_orange_coords.push({curr.first, curr.second + 1});
                    healthy_count --;
                    can_infect = true;
                }

                if (curr.first - 1 >= 0 && grid[curr.first - 1][curr.second] == 1) {
                    grid[curr.first - 1][curr.second] = 2;
                    rotten_orange_coords.push({curr.first - 1, curr.second});
                    healthy_count --;
                    can_infect = true;
                }

                if (curr.second - 1 >= 0 && grid[curr.first][curr.second - 1] == 1) {
                    grid[curr.first][curr.second - 1] = 2;
                    rotten_orange_coords.push({curr.first, curr.second - 1});
                    healthy_count --;
                    can_infect = true;
                }
            }

            if (can_infect) duration ++;
        }

        return healthy_count ? -1 : duration;
    }
};