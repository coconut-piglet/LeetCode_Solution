class Solution {
public:
    int myAtoi(string str) {
        int ret = 0;
        int upperBound = INT_MAX / 10;
        int lowerBound = INT_MIN / 10;
        int sign = 1;
        int pos;
        int length = str.length();
        int next;
        char token;
        for (pos = 0; str[pos] == ' '; pos++); // clean the space
        token = str[pos];
        if (token == '-') {
            sign = -1;
            pos++;
        }
        else if (token == '+') {
            pos++;
        }
        else {
            if (token > '9' || token < '0') return 0; // invalid input
        }
        for (pos; pos < length; pos++) {
            token = str[pos];
            next = (int)token - 48;
            if (token >= '0' && token <= '9') {
                if ((ret == upperBound && next > 7) || ret > upperBound) return INT_MAX;
                if ((ret == lowerBound && next > 8) || ret < lowerBound) return INT_MIN;
                ret = ret * 10 + next * sign;
            }
            else {
                break;
            }
        }
        return ret;
    }
};