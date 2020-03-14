class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // First Attempt
        // int size = nums.size();
        // int num;
        // for (int i = 0; i < size; i++) {
        //     num = nums[i];
        //     if (num <= 0 || num > size) {
        //         nums[i] = -1;
        //         continue;
        //     }
        //     if (num > i + 1) {
        //         if (nums[num - 1] == num) {
        //             nums[i] = -1;
        //             continue;
        //         }
        //         swap(nums[i], nums[num - 1]);
        //         i--;
        //         continue;
        //     }
        //     if (num == i + 1) {
        //         continue;
        //     }
        //     if (num < i + 1) {
        //         nums[num - 1] = nums[i];
        //         nums[i] = -1;
        //         continue;
        //     }
        // }
        // int ret = size;
        // for (int i = 0;i < size; i++) {
        //     if (nums[i] == -1) {
        //         ret = i;
        //         break;
        //     }
        // }
        // return ret + 1;
        // Optimized Solution
        int size = nums.size();
        int num;
        for (int i = 0; i < size; i++) {
            num = nums[i];
            if (num > 0 && num <= size && nums[num - 1] != num) {
                swap(nums[i], nums[num - 1]);
                i--;
            }
        }
        int ret = size;
        for (int i = 0; i < size; i++) {
            if (nums[i] != i + 1) {
                ret = i;
                break;
            }
        }
        return ret + 1;
    }
};