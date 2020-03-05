class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int closestSum, DValue;
        int minDValue = INT_MAX;
        int previous = 0, num0 = 0, num1 = 0, num2 = 0, sum = 0, j = 0, k = 0;
        for (int i = 0; i < size - 2; i++) {
            num0 = nums[i];
            if (i > 0 && num0 == previous) continue; // skip duplication
            j = i + 1;
            k = size - 1;
            while (j < k) {
                num1 = nums[j];
                num2 = nums[k];
                sum = num0 + num1 + num2;
                if (sum > target) {
                    DValue = sum - target;
                    if (DValue < minDValue) {
                        minDValue = DValue;
                        closestSum = sum;
                    }
                    k--; // num2 should get smaller
                }
                else if (sum < target) {
                    DValue = target - sum;
                    if (DValue < minDValue) {
                        minDValue = DValue;
                        closestSum = sum;
                    }
                    j++; // num1 should get larger
                }
                else {
                    return target;
                }
            }
            previous = num0;
        }
        return closestSum;
    }
};