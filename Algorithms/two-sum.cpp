class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Solution 1 Brute Force
        // for (int i = 0; i < nums.size(); i++) {
        //     int toFind = target - nums[i];
        //     for (int j = 0; j < nums.size(); j++) {
        //         if (nums[j] == toFind && j != i) {
        //             vector<int> ret = {i, j};
        //             return ret;
        //         }
        //     }
        // }
        // Solution 2 Semi One-pass Hash Table
		map<int, int> numsTable;
        map<int, int>::iterator iter;
        for (int i = 0; i < nums.size(); i++) {
            numsTable.insert(pair(nums[i], i));
            int toFind = target - nums[i];
            iter = numsTable.find(toFind);
            if (iter != numsTable.end()) {
                if (iter->second == i) continue; // same number used twice
                vector<int> ret = {iter->second, i};
                return ret;
            }
        }
        vector<int> emptyRet;
        return emptyRet;
    }
};