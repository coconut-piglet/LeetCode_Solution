class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int takeStep[n + 1];
        takeStep[0] = 0;
        takeStep[1] = 1;
        takeStep[2] = 2;
        for (int i = 3; i <= n; i++) {
            takeStep[i] = takeStep[i - 1] + takeStep[i - 2];
        }
        return takeStep[n];
    }
};