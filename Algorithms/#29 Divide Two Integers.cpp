class Solution {
public:
    int divide(int dividend, int divisor) {
        // Solution 1 Brute Force
        // if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        // if (divisor == 1) return dividend;
        // if (divisor == -1) return -dividend;
        // bool neg = false;
        // if (dividend >= 0 && divisor < 0) {
        //     neg = true;
        //     dividend = -dividend;
        // }
        // else if (dividend < 0 && divisor > 0) {
        //     neg = true;
        //     divisor = -divisor;
        // }
        // else if (dividend > 0 && divisor > 0) {
        //     dividend = -dividend;
        //     divisor = -divisor;
        // }
        // int ret = 0;
        // while (dividend <= divisor) {
        //     dividend -= divisor;
        //     ret++;
        // }
        // if (neg) ret = -ret;
        // return ret;
        // Solution 2 Bit shift
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;// handle corner case
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;// handle corner case
        bool neg = (dividend > 0) ^ (divisor > 0) ? true : false;// XOR to decide sign
        long long ldividend = labs((long long)dividend);
        long long ldivisor = labs((long long)divisor);
        int quotient = 0;
        int highestPowerOf2 = 0;
        while (ldividend >= ldivisor) {// see comment in README
            highestPowerOf2 = 0;
            while (ldividend >= (ldivisor << highestPowerOf2)) highestPowerOf2++;
            highestPowerOf2--;
            quotient += 1 << highestPowerOf2;
            ldividend -= (ldivisor << highestPowerOf2);
        }
        return neg ? -quotient : quotient;
    }
};