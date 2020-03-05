class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int num0, num1, num2, num3, prev0 = 0, prev1 = 0, m, n, rest, sum2;
        for (int i = 0; i < size - 3; i++) {
            num0 = nums[i];
            if ((num0 > target && target >= 0) || (num0 >=0 && target < 0)) break; // no need to continue, can not get target
            if (i > 0 && num0 == prev0) continue; // skip duplication
            for (int j = i + 1; j < size - 2; j++) {
                num1 = nums[j];
                rest = target - num0;
                if ((num1 > rest && rest >= 0) || (num1 >=0 && rest < 0)) break; // no need to continue, can not get target
                if (j > i + 1 && num1 == prev1) continue;
                rest -= num1;
                m = j + 1;
                n = size - 1;
                while (m < n) {
                    num2 = nums[m];
                    num3 = nums[n];
                    sum2 = num2 + num3;
                    if (sum2 > rest) {
                        n--; // num3 should get smaller
                    }
                    else if (sum2 < rest) {
                        m++; // num2 should get larger
                    }
                    else {
                        ret.push_back({num0, num1, num2, num3});
                        while (m < n - 1  && nums[m] == nums[m + 1]) m++; // skip duplication
                        while (n > m + 1 && nums[n] == nums[n - 1]) n--; // skip duplication
                        m++;
                        n--;
                    }
                }
                prev1 = num1;
            }
            prev0 = num0;
        }
        return ret;
    }
};