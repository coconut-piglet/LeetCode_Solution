class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sumMax = nums[0];
        int size = nums.size();
        for (int i = 1; i < size; i++) {
            nums[i] = nums[i] + nums[i - 1] > nums[i] ? nums[i] + nums[i - 1] : nums[i];
            sumMax = nums[i] > sumMax ? nums[i] : sumMax;
        }
        return sumMax;
    }
};