class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> strToIdx;
        vector<vector<string>> ret;
        string tmp;
        for (string str : strs) {
            tmp = str;
            sort(tmp.begin(),tmp.end());
            if (strToIdx.find(tmp) == strToIdx.end()) {
                strToIdx.insert(pair<string, int>(tmp, ret.size()));
                vector<string> newentry = {str};
                ret.emplace_back(newentry);
            }
            else {
                ret[strToIdx[tmp]].emplace_back(str);
            }
        }
        return ret;
    }
};