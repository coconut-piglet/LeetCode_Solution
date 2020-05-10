class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numOfRow = matrix.size();
        if (numOfRow == 0) return false;
        int numOfCol = matrix[0].size();
        if (numOfCol == 0) return false;
        
        int begin, mid, end;
        int midRow, midNum, midCol;
        
        begin = 0;
        end = numOfRow * numOfCol - 1;
        
        while (begin <= end) {
            mid = (begin + end) >> 1;
            midRow = mid / numOfCol;
            midCol = mid % numOfCol;
            midNum = matrix[midRow][midCol];
            
            if (target < midNum) {
                end = mid - 1;
            }
            else if (target > midNum) {
                begin = mid + 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};