class Solution {
public:
    int mySqrt(int x) {
        if (x == 1) return 1;
        long guess = (long) x >> 1;
        long target = (long) x;
        while (guess * guess > target) {
            guess = (guess + target / guess) >> 1;
        }
        return (int)guess;
    }
};