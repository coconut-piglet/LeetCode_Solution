class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1[0] == '0' || num2[0] == '0') return "0"; // deal with corner case
        
        int len1 = num1.length();
        int len2 = num2.length();
        int len = len1 + len2 - 1;
        int buffer[len];
        for (int i = 0; i < len; i++) buffer[i] = 0;
        
        int i, j;
        int factor1, factor2, product;
        for (i = 0; i < len1; i++) {
            factor1 = num1[i] - '0';
            for (j = 0; j < len2; j++) {
                factor2 = num2[j] - '0';
                product = factor1 * factor2;
                buffer[i + j] += product;
            }
        }
        for (i = len - 1; i > 0; i--) {
            buffer[i - 1] += buffer[i] / 10;
            buffer[i] = buffer[i] % 10;
        }
        if (buffer[0] >= 10) {
            len++;
            string ret(len, '0');
            ret[0] += buffer[0] / 10;
            buffer[0] = buffer[0] % 10;
            for (i = 1; i < len; i++) {
                ret[i] += buffer[i - 1];
            }
            return ret;
        }
        else {
            string ret(len, '0');
            for (i = 0; i < len; i++) {
                ret[i] += buffer[i];
            }
            return ret;
        }
    }
};