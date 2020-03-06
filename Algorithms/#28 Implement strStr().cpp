class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int lenH = haystack.length();
        int lenN = needle.length();
        bool isMatch;
        for (int i = 0; i <= lenH - lenN; i++) {
            if (haystack[i] == needle[0]) {
                isMatch = true;
                for (int j = 1; j < lenN; j++) {
                    if (haystack[i + j] != needle[j]) {
                        isMatch = false;
                        break;
                    }
                }
                if (isMatch) return i;
            }
        }
        return -1;
    }
};