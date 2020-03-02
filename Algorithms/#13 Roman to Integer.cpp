class Solution {
public:
    int romanToInt(string s) {
        map<char, int> dict;
        dict.insert(pair('I', 1));
        dict.insert(pair('V', 5));
        dict.insert(pair('X', 10));
        dict.insert(pair('L', 50));
        dict.insert(pair('C', 100));
        dict.insert(pair('D', 500));
        dict.insert(pair('M', 1000));
        int ret = 0;
        int len = s.length();
        int current = dict[s[0]];
        if (len == 1) return current;
        int next = current;
        for (int i = 0; i < len - 1; i++) {
            current = next;
            next = dict[s[i + 1]];
            ret += current < next ? -current : current;
        }
        ret += next;
        return ret;
    }
};