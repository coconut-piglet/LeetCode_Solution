class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> combination;
        findCombination(candidates, 0, target, ret, combination);
        return ret;
    }
private:
    void findCombination(vector<int>& candidates, int pos, int target, vector<vector<int>>& ret, vector<int>& combination) {
        if (candidates[pos] > target) {// can not get target since candidates is sorted and inputs are positive integers
            return;// abort recursion
        }
        // case1, skip this element
        if (pos + 1 < candidates.size()) findCombination(candidates, pos + 1, target, ret, combination);
        // case2, choose this element (and can be choose multiple times until abort condition is hit)
        combination.push_back(candidates[pos]);
        target -= candidates[pos];
        if (target == 0) {
            ret.push_back(combination); // put current combination to the ret set
            combination.pop_back();
            return;
        }
        findCombination(candidates, pos, target, ret, combination);// pick this time
        combination.pop_back();
        return;
    }
};