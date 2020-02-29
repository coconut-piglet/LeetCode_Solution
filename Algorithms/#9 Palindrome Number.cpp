class Solution {
public:
    bool isPalindrome(int x) {
        // Solution 1 Scan from both side
        // if (x < 0) return false;
        // string str = to_string(x);
        // int low = 0;
        // int high = str.length() - 1;
        // while (low < high) {
        //     if (str[low] == str[high]) {
        //         low++;
        //         high--;
        //     }
        //     else {
        //         return false;
        //     }
        // }
        // Solution 2 Revert half of the number
        if (x < 0) return false;
        if (x > 0 && x % 10 == 0) return false;
        int mirror = 0;
        while (x > mirror) {
            mirror = mirror * 10 + x % 10;
            x = x / 10;
        }
        if (x != mirror && x != mirror / 10) return false;
        return true;
    }
};