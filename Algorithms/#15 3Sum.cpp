class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int target = 0, previous = 0, num1 = 0, num2 = 0, sum = 0, j = 0, k = 0;
        for (int i = 0; i < size - 2; i++) {
            target = nums[i];
            if (target > 0) break; // no need to continue, can not get 0
            if (i > 0 && target == previous) continue; // skip duplication
            j = i + 1;
            k = size - 1;
            cout << target << endl;
            while (j < k) {
                num1 = nums[j];
                num2 = nums[k];
                sum = num1 + num2;
                if (sum + target > 0) {
                    k--; // num2 should get smaller
                }
                else if (sum + target < 0) {
                    j++; // num1 should get larger
                }
                else {
                    ret.push_back({target, num1, num2});
                    while (j < k - 1 && nums[j] == nums[j + 1]) j++; // skip duplication
                    while (k > j + 1 && nums[k] == nums[k - 1]) k--; // skip duplication
                    j++;
                    k--;
                }
            }
            previous = target;
        }
        return ret;
    }
};