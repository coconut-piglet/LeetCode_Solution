class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        size = nums.size();
        bool keep[size];
        solveSubsets(nums, 0, ret, keep);
        return ret;
    }
private:
    int size;
    vector<int> current;
    void solveSubsets(vector<int>& nums, int index, vector<vector<int>>& ret, bool* keep) {
        /* reach end */
        if (index == size) {
            current.clear();
            for (int i = 0; i < size; i++) {
                if (keep[i]) current.push_back(nums[i]);
            }
            ret.push_back(current);
            return;
        }
        /* skip index */
        keep[index] = false;
        solveSubsets(nums, index + 1, ret, keep);
        /* keep index */
        keep[index] = true;
        solveSubsets(nums, index + 1, ret, keep);
    }
};