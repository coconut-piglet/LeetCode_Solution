class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = countAndSay(n - 1);
        string ret;
        int count = 1;
        for (int i = 0; i < prev.length(); i++) {
            if (prev[i + 1] == prev[i]) {
                count++;
            }
            else {
                ret += to_string(count);
                ret += prev[i];
                count = 1;
            }
        }
        return ret;
    }
};