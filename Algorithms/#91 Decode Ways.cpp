class Solution {
public:
    int numDecodings(string s) {
        int length = s.length();
        if (length == 0) return 0; // deal with corner case
        int prev = (int)s[0] - 48;
        if (prev == 0) return 0; // deal with corner case
        if (length == 1) return 1; // deal with corner case
        int current;
        int waysPrev2, waysPrev1, ways;
        waysPrev2 = 1;
        waysPrev1 = 1;
        for (int i = 1; i < length; i++) {
            current = (int)s[i] - 48;
            if (current == 0) {
                if (prev != 1 && prev != 2) return 0;
                ways = waysPrev2;
            }
            else {
                ways = waysPrev1;
                if (prev == 1 || (prev == 2 && current < 7)) {
                    ways += waysPrev2;
                }
            }
            prev = current;
            waysPrev2 = waysPrev1;
            waysPrev1 = ways;
        }
        return ways;
    }
};