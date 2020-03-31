class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int rowMove = matrix.size();
        if (rowMove == 0) return ret;
        int colMove = matrix[0].size();
        int left = rowMove * colMove;
        int row = 0, col = -1, direction = 1;
        rowMove--;
        while (left > 0) {
            for (int i = 0; i < colMove; i++) {
                col += direction;
                ret.emplace_back(matrix[row][col]);
                left--;
            }
            for (int i = 0; i < rowMove; i++) {
                row += direction;
                ret.emplace_back(matrix[row][col]);
                left--;
            }
            rowMove--;
            colMove--;
            direction = -direction;
        }
        return ret;
    }
};