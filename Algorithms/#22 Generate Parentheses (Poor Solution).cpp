class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if (n == 0) {
            ret.emplace_back("");
        }
        else {
            for (int i = 0; i < n; i++) {
                vector<string> leftSet = generateParenthesis(i);
                vector<string> rightSet = generateParenthesis(n - i - 1);
                for (string left : leftSet) {
                    for (string right : rightSet) {
                        ret.emplace_back("(" + left + ")" + right);
                    }
                }
            }
        }
        return ret;
    }
};