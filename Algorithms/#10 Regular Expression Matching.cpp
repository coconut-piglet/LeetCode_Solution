class Solution {
public:
    bool isMatch(string s, string p) {
        // Learnt from https://youtu.be/l3hda49XcDE
        int lenS = s.length();
        int lenP = p.length();
        char tokenS, tokenP;
        bool isMatch[lenS + 1][lenP + 1];
		isMatch[0][0] = true; // empty s vs empty p, s is valid
        for (int i = 1; i <= lenP; i++) { // empty s vs none empty p, mostly all s are invalid
            isMatch[0][i] = false;
        }
        for (int i = 1; i <= lenS; i++) { // none empty s vs empty p, all s are invalid
            isMatch[i][0] = false;
        }
		for (int i = 2; i <= lenP; i++) { // deal with a*b* alike situation
			if (p[i - 1] == '*') {
				isMatch[0][i - 1] = isMatch[0][i - 2];
				isMatch[0][i] = isMatch[0][i - 2];
			}
		}
        for (int i = 1; i <= lenS; i++) {
            for (int j = 1; j <= lenP; j++) {
                tokenS = s[i - 1];
                tokenP = p[j - 1];
				if (tokenP == '.' || tokenS == tokenP) { // matches
					isMatch[i][j] = isMatch[i - 1][j - 1];
				}
				else if (tokenP == '*') {
					if (p[j - 2] == '.' || tokenS == p[j - 2]) {
						isMatch[i][j] = isMatch[i][j - 2] || isMatch[i - 1][j]; // the word in front of '*' occurs 0+ times
					}
					else {
						isMatch[i][j] = isMatch[i][j - 2]; // the word in front of '*' occurs 0 times
					}
				}
				else {
					isMatch[i][j] = false; // default false
				}
            }
        }
        return isMatch[lenS][lenP];
    }
};