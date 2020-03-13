class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int count = n/2,temp = 0;// has n/2 layer
        for(int i = 0;i < count;++i){
            for(int j = i;j<n-i-1;++j){// for each layer, the left corner is [i,i], should stop at n - 1 - i
                temp = matrix[i][j];// swap four times in one cycle
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
        return;
    }
};