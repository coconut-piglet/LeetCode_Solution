class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // Solution 1 Limited Recursion (Only use the provided function)
        // vector<vector<int>> ret;
        // vector<vector<int>> tmp;
        // int size = nums.size();
        // if (size == 1) {
        //     ret.emplace_back(nums);
        //     return ret;
        // };
        // for (int i = 0; i < size; i++) {
        //     int pick = nums[i];
        //     swap(nums[0], nums[i]);
        //     nums.erase(nums.begin());
        //     tmp = permute(nums);
        //     for (vector<int> permutation : tmp) {
        //         permutation.insert(permutation.begin(), pick);
        //         ret.emplace_back(permutation);
        //     }
        //     nums.insert(nums.begin(), pick);
        //     swap(nums[0], nums[i]);
        // }
        // return ret;
        // Solution 2 Optimized Recursion (Use improved function)
        // Reference: https://leetcode.com/problems/permutations/discuss/525691/Simple-and-easy-to-understand-C%2B%2B-using-recursion-98-faster-100-memory
        vector<vector<int>> ret;
        permute_plus(0, &nums, &ret);
        return ret;
    }
private:
    void permute_plus(int pos, vector<int>* inputLine, vector<vector<int>>* ret) {// use reference to save space
        vector<int>& nums = *inputLine;
        int size = nums.size();
        if (pos == size - 1) {
            ret -> emplace_back(nums);
            return;
        }
        for (int j = pos; j < size; ++j) {
            swap(nums[pos], nums[j]);
            permute_plus(pos + 1, inputLine, ret);
            swap(nums[pos], nums[j]);
        }
    }
};