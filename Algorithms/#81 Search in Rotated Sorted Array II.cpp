class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int size = nums.size();
        int low, mid, high, lowNum, midNum, highNum;
        low = 0;
        high = size - 1;
        while (low <= high) {
            mid = (low + high) >> 1;
            lowNum = nums[low];
            midNum = nums[mid];
            highNum = nums[high];
            
            if (target > midNum) {
                if (target == highNum) {
                    return true;
                }
                else if (target < highNum) {
                    low = mid + 1;
                    high = high - 1;
                }
                else if (highNum < midNum) {
                    low = mid + 1;
                    high = high - 1;
                }
                else if (highNum > midNum) {
                    high = mid - 1;
                }
                else {
                    high--;
                }
            }
            else if (target < midNum) {
                if (target == lowNum) {
                    return true;
                }
                else if (target > lowNum) {
                    low = low + 1;
                    high = mid - 1;
                }
                else if (lowNum > midNum) {
                    low = low + 1;
                    high = mid - 1;
                }
                else if (lowNum < midNum) {
                    low = mid + 1;
                }
                else {
                    low++;
                }
            }
            else {
                return true;
            }
        }
        return false;
    }
};