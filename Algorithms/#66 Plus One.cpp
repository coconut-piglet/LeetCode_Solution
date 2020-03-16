class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // First Attempt
        // int size = digits.size() - 1;
        // digits[size]++;
        // for (int i = size; i >= 0; i--) {
        //     if (digits[i] > 9) {
        //         digits[i] -= 10;
        //         if (i != 0) {
        //             digits[i - 1]++;
        //         }
        //         else {
        //             digits.insert(digits.begin(), 1);
        //         }
        //     }
        // }
        // return digits;
        // Optimized Solution
        int size = digits.size() - 1;
        digits[size]++;
        for (int i = size; i >= 0; i--) {
            if (digits[i] != 10) break;
            digits[i] = 0;
            if (i == 0) {
                digits.insert(digits.begin(), 1);
            }
            else {
                digits[i - 1]++;
            }
        }
        return digits;
    }
};