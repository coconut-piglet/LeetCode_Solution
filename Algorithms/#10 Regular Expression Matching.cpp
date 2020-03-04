class Solution {
public:
    bool isMatch(string s, string p) {
        int lenS = s.length();
        int lenP = p.length();
        char tokenS, tokenP;
        bool isMatch[lenS + 1][lenP + 1];
        for (int i = 1; i <= lenP; i++) {
            isMatch[0][i] = false;
        }
        for (int i = 0; i <= lenS; i++) {
            isMatch[i][0] = true;
        }
        for (int i = 1; i <= lenS; i++) {
            for (int j = 1; j <= lenP; j++) {
                tokenS = s[i];
                tokenP = p[j];
                if (tokenP != '*') {
                    isMatch[i][j] = isMatch[i - 1][j - 1] && (tokenS == tokenP);
                }
                else {
                    isMatch[i][j] = isMatch[i][j - 2] || (isMatch[i - 1][j] && (tokenS == p[j - 1]));
                }
            }
        }
        return isMatch[lenS][lenP];
    }
};