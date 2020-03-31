class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        end = word.length();
        search = word;
        char current;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                current = board[i][j];
                if (current == search[0]) {
                    board[i][j] = '*';
                    if (findNext(board, 1,i,j)) return true;
                    board[i][j] = current;
                }
            }
        }
        return false;
    }
private:
    int row, col, end;
    int moveRow[4] = {1, -1, 0, 0};
    int moveCol[4] = {0, 0, 1, -1};
    string search;
    bool findNext(vector<vector<char>>& board, int index, int startRow, int startCol) {
        if (index == end) return true;
        int rowToFind, colToFind;
        char toFind = search[index];
        char current;
        for (int i = 0; i < 4; i++) {
            rowToFind = startRow + moveRow[i];
            colToFind = startCol + moveCol[i];
            if (rowToFind < 0 || rowToFind == row || colToFind < 0 || colToFind == col) continue;
            current = board[rowToFind][colToFind];
            if (current == toFind) {
                board[rowToFind][colToFind] = '*';
                if (findNext(board, index + 1, rowToFind, colToFind)) return true;
                board[rowToFind][colToFind] = current;
            }
        }
        return false;
    }
};