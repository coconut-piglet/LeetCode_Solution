class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Solution 1 Intuitive Solution
        // for (int i = 1; i < nums.size(); i++) {
        //     if (nums[i] == nums[i - 1]) {
        //         nums.erase(nums.begin() + i);
        //         i--;
        //     }
        // }
        // return nums.size();
        // Solution2 Two Pointers
        if (nums.size() == 0) return 0;// stupid corner case
        int frontPtr = 0, backPtr = 0;
        while (frontPtr < nums.size()) {
            if (nums[frontPtr] != nums[backPtr]) {
                backPtr++;
                swap(nums[frontPtr], nums[backPtr]);
            }
            frontPtr++;
        }
        nums.erase(nums.begin() + backPtr + 1, nums.end());
        return nums.size();
    }
};