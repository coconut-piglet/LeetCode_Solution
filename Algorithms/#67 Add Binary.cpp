class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length() - 1;
        int len2 = b.length() - 1;
        bool carry = false;
        list<char> buffer;
        string ret = "";
        char tmp;
        while (len1 >= 0 && len2 >= 0) {
            tmp = a[len1] + b[len2] - 48;
            if (carry) tmp++;
            if (tmp > '1') {
                carry = true;
                tmp -= 2;
            }
            else {
                carry = false;
            }
            buffer.push_back(tmp);
            len1--;
            len2--;
        }
        while (len1 >= 0) {
            tmp = a[len1];
            if (carry) tmp++;
            if (tmp > '1') {
                carry = true;
                tmp -= 2;
            }
            else {
                carry = false;
            }
            buffer.push_back(tmp);
            len1--;
        } 
        while (len2 >= 0) {
            tmp = b[len2];
            if (carry) tmp++;
            if (tmp > '1') {
                carry = true;
                tmp -= 2;
            }
            else {
                carry = false;
            }
            buffer.push_back(tmp);
            len2--;
        }
        if (carry) buffer.push_back('1');
        while (!buffer.empty()) {
            ret += buffer.back();
            buffer.pop_back();
        }
        return ret;
    }
};