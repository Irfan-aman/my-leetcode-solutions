class Solution {
public:
    // bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
    //     // row
    //     for (int i = 0; i < 9; i++) {
    //         if (i != r && board[i][c] == ch)
    //             return false;
    //     }
    //     // column
    //     for (int j = 0; j < 9; j++) {
    //         if (j != c && board[r][j] == ch)
    //             return false;
    //     }
    //     // 3*3 box
    //     int sr = r / 3 * 3, sc = c / 3 * 3;
    //     for (int i = sr; i < sr + 3; i++) {
    //         for (int j = sc; j < sc + 3; j++) {
    //             if ((i != r && j != c) && board[i][j] == ch)
    //                 return false;
    //         }
    //     }
    //     return true;
    // }
    // bool solve(vector<vector<char>>& board) {
    //     for (int i = 0; i < 9; i++) {
    //         for (int j = 0; j < 9; j++) {
    //             if (board[i][j] == '.')
    //                 continue;
    //             else if (!isValid(board, i, j, board[i][j]))
    //                 return false;
    //         }
    //     }
    //     return true;
    // }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int val = board[i][j] -
                          '1'; // converting char to index 1-9 to 0 to 8 idx
                int boxIdx = i / 3 * 3 + j / 3;
                if (row[i][val] || col[j][val] || box[boxIdx][val])
                    return false;
                row[i][val] = true;
                col[j][val] = true;
                box[boxIdx][val] = true;
            }
        }
        return true;
    }
};