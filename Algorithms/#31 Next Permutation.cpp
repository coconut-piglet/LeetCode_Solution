class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int peak = 0;
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                peak = i;
                break;
            }
        }
        if (peak == 0) {
            sort(nums.begin(),nums.end());
        }
        else {
            int lowerBound = nums[peak - 1];
            int toSwap;
            for (int i = peak; i < nums.size(); i++) {
                if (nums[i] > lowerBound) {
                    toSwap = i;
                }
                else {
                    break;
                }
            }
            swap(nums[peak - 1], nums[toSwap]);
            sort(nums.begin() + peak, nums.end());
        }
        return;
    }
};