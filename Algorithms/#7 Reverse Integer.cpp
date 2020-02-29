class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        int tmp = 0;
        int upperBound = INT_MAX / 10;
        int lowerBound = INT_MIN / 10;
        do {
            tmp = x % 10;
            x = x / 10;
            if (ret > upperBound || ret < lowerBound) return 0;
            if (ret == upperBound && tmp > 7) return 0;
            if (ret == lowerBound && tmp < -8) return 0;
            ret = ret * 10 + tmp;
        } while (x != 0);
        return ret;
    }
};