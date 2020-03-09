class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Insane Simple Solution
        // return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
        // My Normal Solution
        int separator = 0;
        for (int toTest = 0; toTest < nums.size(); toTest++) {
            if (nums[toTest] != val) {
                nums[separator] = nums[toTest];
                separator++;
            }
        }
        nums.erase(nums.begin() + separator, nums.end());
        return separator;
    }
};