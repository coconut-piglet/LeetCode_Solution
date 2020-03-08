class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        vector<vector<int>> ret;
        findCombinationSum(candidates, 0, target, combination, ret);
        return ret;
    }
private:
    void findCombinationSum(vector<int>& candidates, int pos, int target, vector<int>& combination, vector<vector<int>>& ret) {
        if (candidates[pos] > target) {
            return; // abort
        }
        // case 1 not pick this candidate, once not pick, ignore all same element
        int next = pos;
        for (int i = pos + 1; i < candidates.size(); i++) {
            if (candidates[i] == candidates[pos]) {
                next = i;
            }
            else {
                break;
            }
        }
        if (next < candidates.size() - 1) {
            findCombinationSum(candidates, next + 1, target, combination, ret);
        }
        // case 2 pick this candidate
        target -= candidates[pos];
        combination.push_back(candidates[pos]);
        if (target == 0) {
            ret.push_back(combination);
            combination.pop_back();
            return;// success
        }
        else if (pos < candidates.size() - 1) {
            findCombinationSum(candidates, pos + 1, target, combination, ret);
            combination.pop_back();
        }
        else {
            // also abort
            combination.pop_back();
        }
        return;
    }
};