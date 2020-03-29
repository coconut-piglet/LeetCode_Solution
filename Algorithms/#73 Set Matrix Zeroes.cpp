class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool row0 = false, col0 = false;
        /* deal with first row */
        for (int i = 1; i < row; i++) {
            if (matrix[i][0] == 0) {
                col0 = true;
                break;
            }
        }
        /* deal with first col */
        for (int j = 1; j < col; j++) {
            if (matrix[0][j] == 0) {
                row0 = true;
                break;
            }
        }
        /* deal with first element */
        if (matrix[0][0] == 0) {
            row0 = true;
            col0 = true;
        }
        /* deal with others */
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        /* iterate once more to mark 0 */
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (row0) {
            for (int j = 0; j < col; j++) matrix[0][j] = 0;
        }
        if (col0) {
            for (int i = 0; i < row; i++) matrix[i][0] = 0;
        }
    }
};