class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        if (high < 0) {
            vector<int> ret = {-1, -1};
            return ret;
        }
        int mid;
        int start, end;
        while (low < high) {// should find the lower bound
            mid = (low + high) >> 1;
            if (nums[mid] >= target) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        if (nums[low] != target) {
            vector<int> ret = {-1, -1};
            return ret;
        }
        start = low;
        high = nums.size() - 1;
        while (low < high) {// should find the upper bound
            mid = (low + high) >> 1;
            if (nums[mid] > target) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        if (nums[low] != target) {
            low--;
        }
        end = low;
        vector<int> ret = {start, end};
        return ret;
    }
};