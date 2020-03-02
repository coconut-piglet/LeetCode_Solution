class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        int minLength = INT_MAX;
        int length = 0;
        int numOfStrs = strs.size();
        if (numOfStrs == 0) return ret;
        int count = 0;
        char current, next;
        for (string s : strs) {
            length = s.length();
            minLength = minLength > length ? length : minLength;
        }
        for (int i = 0; i < minLength; i++) {
            count = 0;
            current = strs[0][i];
            next = current;
            for (int j = 0; j < numOfStrs - 1; j++) {
                current = next;
                next = strs[j + 1][i];
                if (current != next) break;
                count++;
            }
            if (count + 1 != numOfStrs) break;
            ret += current;
        }
        return ret;
    }
};