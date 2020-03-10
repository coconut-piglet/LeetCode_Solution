class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1, mid;
        while (low <= high) {
            mid = (low + high) >> 1;// use bit operation to perform division
            if (nums[mid] == target) return mid;
            if (nums[low] <= nums[mid]) {// left half is sorted
                if (target >= nums[low] && target <= nums[mid]) high = mid - 1;// and target is in left half
                else low = mid + 1;// target is not in left half,
            }
            else {// right half is sorted
                if (target >= nums[mid] && target <= nums[high]) low = mid + 1;// and target is in right half
                else high = mid - 1;// target is not in right half
            }
        }
        return -1;
    }
};