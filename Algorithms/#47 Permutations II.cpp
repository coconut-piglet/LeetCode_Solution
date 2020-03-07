class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        permute_plus(0, &nums, &ret);
        return ret;
    }
private:
    void permute_plus(int pos, vector<int>* inputLine, vector<vector<int>>* ret) {
        vector<int>& nums = *inputLine;
        int size = nums.size();
        vector<int> seen;
        if (pos == size - 1) {
            ret -> emplace_back(nums);
            return;
        }
        for (int i = pos; i < size; ++i) {
            swap(nums[pos], nums[i]);
            if (find(seen.begin(), seen.end(), nums[pos]) == seen.end()) {
                seen.emplace_back(nums[pos]);
                permute_plus(pos + 1, inputLine, ret);
            }
            swap(nums[pos], nums[i]);
        }
    }
};