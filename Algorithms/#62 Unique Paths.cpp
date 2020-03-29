class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        int numOfPaths[n][m];
        numOfPaths[0][0] = 0;
        for (int i = 1; i < n; i++) numOfPaths[i][0] = 1;
        for (int i = 1; i < m; i++) numOfPaths[0][i] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                numOfPaths[i][j] = numOfPaths[i - 1][j] + numOfPaths[i][j - 1];
            }
        }
        return numOfPaths[n - 1][m - 1];
    }
};