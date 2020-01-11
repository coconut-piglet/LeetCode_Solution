class Solution {
public:
    string longestPalindrome(string s) {
        int length, lowerbound, upperbound, offset, maxLength = 0, currentLength;
        length = s.size();
        string ret;
        for (int i = 0; i < length; i++) {
            lowerbound = i;
            for (int j = i; j < length; j++) {
                if (s[i] != s[j]) break;
                upperbound = j;
            }
            for (offset = 1; offset <= lowerbound && offset <= (length - upperbound - 1); offset++) {
                if (s[lowerbound - offset] != s[upperbound + offset]) break;
            }
            offset = offset - 1;
            currentLength = offset + upperbound - lowerbound + 1 + offset;
            if (currentLength > maxLength) {
                maxLength = currentLength;
                ret = s.substr(lowerbound - offset, maxLength);
            }
            i = upperbound;
        }
        return ret;
    }
};