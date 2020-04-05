class Solution {
public:
    bool isMatch(string s, string p) {
        int lenS = s.length();
        int lenP = p.length();
        bool isMatch[lenS + 1][lenP + 1];
        char tokenP;
        int i, j;
        isMatch[0][0] = true;
        for (i = 1; i <= lenS; i++) isMatch[i][0] = false;
        for (j = 0; j < lenP; j++) {
            if (p[j] != '*') break;
            isMatch[0][j + 1] = true;
        }
        for (j++; j <= lenP; j++) isMatch[0][j] = false;
        for (i = 1; i <= lenS; i++) {
            for (j = 1; j <= lenP; j++) {
                tokenP = p[j - 1];
                if (tokenP == '?' || tokenP == s[i - 1]) {
                    isMatch[i][j] = isMatch[i - 1][j - 1];
                }
                else if (tokenP == '*') {
                    isMatch[i][j] = isMatch[i - 1][j - 1] || isMatch[i - 1][j] || isMatch[i][j - 1];
                }
                else {
                    isMatch[i][j] = false;
                }
            }
        }
        return isMatch[lenS][lenP];
    }
};