class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<int> row(9, 0), col(9, 0), box(9, 0);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int numRow = board[i][j] - '1';
                    if (row[numRow]++) return false;  
                }
                if (board[j][i] != '.') {
                    int numCol = board[j][i] - '1';
                    if (col[numCol]++) return false;  
                }
                int boxRow = 3 * (i / 3) + j / 3;
                int boxCol = 3 * (i % 3) + j % 3;
                if (board[boxRow][boxCol] != '.') {
                    int numBox = board[boxRow][boxCol] - '1';
                    if (box[numBox]++) return false;  
                }
            }
        }
        return true;
    }
};
