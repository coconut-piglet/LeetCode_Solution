class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Solution 1 Use Set to Record
        // set<char> seenRow;
        // set<char> seenCol;
        // for (int i = 0; i < 9; i++) {
        //     seenRow.clear();
        //     seenCol.clear();
        //     for (int j = 0; j < 9; j++) {
        //         if (board[i][j] != '.') {
        //             if (seenRow.find(board[i][j]) == seenRow.end()) {
        //                 seenRow.insert(board[i][j]);
        //             }
        //             else {
        //                 return false;
        //             }
        //         }
        //         if (board[j][i] != '.') {
        //             if (seenCol.find(board[j][i]) == seenCol.end()) {
        //                 seenCol.insert(board[j][i]);
        //             }
        //             else {
        //                 return false;
        //             }
        //         }
        //     }
        // }
        // for (int i = 0; i < 9; i += 3) {
        //     for (int j = 0; j < 9; j += 3) {
        //         seenRow.clear();
        //         for (int m = i; m < i + 3; m++) {
        //             for (int n = j; n < j + 3; n++) {
        //                 if (board[m][n] != '.') {
        //                     if (seenRow.find(board[m][n]) == seenRow.end()) {
        //                         seenRow.insert(board[m][n]);
        //                     }
        //                     else {
        //                         return false;
        //                     }
        //                 }
        //             }
        //         }
        //     }
        // }
        // return true;
        // Solution 2 Use Index to Check
        vector<bool> appearInit(10, false);// so that index can be '9'
        vector<bool> appear;
        for (int i = 0; i < 9; i++) {
            appear = appearInit;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (!appear[board[i][j] -'0']) {
                        appear[board[i][j] -'0'] = true;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        for (int i = 0; i < 9; i++) {
            appear = appearInit;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (!appear[board[j][i] -'0']) {
                        appear[board[j][i] -'0'] = true;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                appear = appearInit;
                for (int m = i; m < i + 3; m++) {
                    for (int n = j; n < j + 3; n++) {
                        if (board[m][n] != '.') {
                            if (!appear[board[m][n] -'0']) {
                                appear[board[m][n] -'0'] = true;
                            }
                            else {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};