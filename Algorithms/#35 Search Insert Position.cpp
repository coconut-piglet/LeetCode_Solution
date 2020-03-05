class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int low = 0;
        int high = size - 1;
        int mid, midNum;
        if (target < nums[0]) return 0;
        if (target > nums[size - 1]) return size;
        while (low < high) {
            mid = (low + high) >> 1;
            midNum = nums[mid];
            if (target > midNum) {
                low = ++mid; // the lower bound needs to increase to prevent mid = low while high = low + 1, also helps find the right position
            }
            else if (target < midNum) {
                high = mid;
            }
            else {
                return mid;
            }
        }
        return mid;
    }
};