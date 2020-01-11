class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Solution 1 Sliding Window Optimized But Slow
        // int length = 1, startPos = 0, maxLength = 0, position;
        // string currentStr, nextChar;
        // while (startPos + length <= s.length()) {
        //     currentStr = s.substr(startPos, length);
        //     nextChar = s.substr(startPos + length, 1);
        //     position = currentStr.find(nextChar);
        //     if (position == s.npos) {
        //         length = length + 1;
        //     }
        //     else {
        //         length = length - position;
        //         startPos = startPos + position + 1;
        //     }
        //     if (length > maxLength) maxLength = length;
        // }
        // return maxLength;
        // Solution 2 Sliding Windows Optimized Fast (Using Map)
        int currentLength = 0, maxLength = 0, startPos = 0;
        map<char, int> posOfAlpha;
        map<char, int>::iterator iter;
        for (int i = 0; i < s.length(); i++) {
            iter = posOfAlpha.find(s[i]);
            if (iter == posOfAlpha.end()) {
                posOfAlpha.insert(pair(s[i], i));
                currentLength++;
            }
            else if (iter->second < startPos) {
                iter->second = i;
                currentLength++;
            }
            else {
                currentLength = currentLength - (iter->second - startPos);
                startPos = iter->second + 1;
                iter->second = i;
            }
            if (currentLength > maxLength) maxLength = currentLength;
        }
        return maxLength;
    }
};