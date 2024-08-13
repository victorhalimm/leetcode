#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:

    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            // Hash the first element
            size_t hash1 = hash<T1>{}(p.first);
            // Hash the second element
            size_t hash2 = hash<T2>{}(p.second);
            // Combine the two hash values
            return hash1
               ^ (hash2 + 0x9e3779b9 + (hash1 << 6)
                  + (hash1 >> 2));
        }
    };

    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_map<pair<int, int>, unordered_set<char>, hash_pair> square;
        unordered_map<int, unordered_set<char>> row;
        unordered_map<int, unordered_set<char>> col;

        for (int i = 0; i < 9; i ++) {

            vector<char> currRow = board[i];

            for (int j = 0; j < 9; j ++) {

                if (currRow[j] == '.')
                    continue;

                pair<int, int> coord(i / 3, j / 3);

                if (row[i].find(currRow[j]) != row[i].end() || 
                    col[j].find(currRow[j]) != col[j].end() || 
                    square[coord].find(currRow[j]) != square[coord].end()) {
                        return false;
                    }
                row[i].insert(currRow[j]);
                col[j].insert(currRow[j]);
                square[coord].insert(currRow[j]);

            }
            
        }

        return true;

    }
};

