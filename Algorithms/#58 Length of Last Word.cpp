class Solution {
public:
    int lengthOfLastWord(string s) {
        int pos = s.length() - 1;
        if (pos == -1) return 0;
        int ret = 0;
        while (s[pos] == ' ') {
            pos--;
            if (pos < 0) return 0;
        }
        while (s[pos] != ' ') {
            ret++;
            pos--;
            if (pos < 0) break;
        }
        return ret;
    }
};