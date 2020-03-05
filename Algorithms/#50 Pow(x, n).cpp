class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        double sqrt, ret;
        if (n > 0) {
            sqrt = myPow(x, n >> 1);// shift bit operation
            ret = sqrt * sqrt;
            if (n & 0x1 == 1) ret *= x;// only odd number has its least significant bit set to 1
        }
        else {
            sqrt = myPow(x, - (n / 2));
            ret = 1 / (sqrt * sqrt);
            if (n & 0x1 == 1) ret /= x;// only odd number has its least significant bit set to 1
        }
        return ret;
    }
};