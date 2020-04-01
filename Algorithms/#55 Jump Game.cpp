class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Intuitive Solution
        // int size = nums.size();
        // bool isReachable[size];
        // for (int i = 1; i < size; i++) isReachable[i] = false;
        // isReachable[0] = true;
        // for (int i = 0; i < size; i++) {
        //     if (isReachable[i]) {
        //         for (int j = 1; j <= nums[i]; j++) {
        //             if (i + j >= size) break;
        //             isReachable[i + j] = true;
        //         }
        //     }
        // }
        // return isReachable[size - 1];
        // Greedy Approach
        int size = nums.size();
        int lastReachable = size - 1;
        for (int i = lastReachable; i >= 0; i--) {
            if (i + nums[i] >= lastReachable) lastReachable = i;
        }
        if (lastReachable == 0) return true;
        return false;
    }
};