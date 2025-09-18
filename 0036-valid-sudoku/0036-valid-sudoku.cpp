class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int BOARD_SIZE = 9;

        // 0 0 -> 0 8 (3)
        // 

        unordered_map<int, unordered_set<int>> row, col, box;

        for (int i = 0; i < BOARD_SIZE; i ++) {
            for (int j = 0; j < BOARD_SIZE; j ++) {
                if (board[i][j] == '.') continue;
                if (row[i].count(board[i][j])) return false;
                if (col[j].count(board[i][j])) return false;

                int determineY = (i / 3) * 3;
                int determineX = j / 3;

                int boxIdx = determineY + determineX;

                if (box[boxIdx].count(board[i][j])) return false;

                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                box[boxIdx].insert(board[i][j]);
            }
        }

        return true;
    }
};