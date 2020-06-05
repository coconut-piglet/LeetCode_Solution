class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        /* corner case, the start point is blocked */
        if (obstacleGrid[0][0] != 0) return 0;
        
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        
        obstacleGrid[0][0] = 1;
        /* init the first col */
        for (int i = 1; i < row; i++) {
            if (obstacleGrid[i][0] != 0) obstacleGrid[i][0] = 0;
            else obstacleGrid[i][0] = obstacleGrid[i - 1][0];
        }
        /* init the first row */
        for (int i = 1; i < col; i++) {
            if (obstacleGrid[0][i] != 0) obstacleGrid[0][i] = 0;
            else obstacleGrid[0][i] = obstacleGrid[0][i - 1];
        }
        /* the path to current point equals the sum of path to its up and left side */
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (obstacleGrid[i][j] != 0) {
                    obstacleGrid[i][j] = 0;
                }
                else {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                }
            }
        }
        
        return obstacleGrid[row - 1][col - 1];
    }
};