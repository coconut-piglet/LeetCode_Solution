class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> blankRow(n, 0);
        vector<vector<int>> matrix(n, blankRow);
        int rowMove = n - 1, colMove = n;
        int current = 1, target = n * n;
        int row = 0, col = -1, step = 1;
        while (current <= target) {
            for (int i = 0; i < colMove; i++) {
                col += step;
                matrix[row][col] = current;
                current++;
            }
            for (int i = 0; i < rowMove; i++) {
                row += step;
                matrix[row][col] = current;
                current++;
            }
            rowMove--;
            colMove--;
            step = -step;
        }
        return matrix;
    }
};