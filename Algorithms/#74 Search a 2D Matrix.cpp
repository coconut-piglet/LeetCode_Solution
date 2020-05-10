class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numOfRow = matrix.size() - 1;
        if (numOfRow < 0) return false;
        int numOfCol = matrix[0].size() - 1;
        if (numOfCol < 0) return false;
        
        if (target < matrix[0][0] || target > matrix[numOfRow][numOfCol]) return false;
        
        int low, mid, high;
        low = 0;
        high = numOfRow;
        
        while (low < high) {
            mid = (low + high) >> 1;
            if (target < matrix[mid][0]) {
                high = mid - 1;
            }
            else if (target > matrix[mid][numOfCol]){
                low = mid + 1;
            }
            else {
                low = mid;
                break;
            }
        }
        
        int targetRow = low;
        if (target < matrix[targetRow][0] || target > matrix[targetRow][numOfCol]) return false;
        
        low = 0;
        high = numOfCol;
        
        while (low <= high) {
            mid = (low + high) >> 1;
            if (target < matrix[targetRow][mid]) {
                high = mid - 1;
            }
            else if (target > matrix[targetRow][mid]) {
                low = mid + 1;
            }
            else {
                return true;
            }
        }
        
        return false;
    }
};