class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        int left_position = 0, left_current = 0, left_max = 0;
        int right_position = height.size() - 1, right_current = 0, right_max = 0;
        while (left_position < right_position) {
            left_current = height[left_position];
            right_current = height[right_position];
            if (left_current < right_current) {
                if (left_current >= left_max) left_max = left_current;
                else ret += (left_max - left_current);
                left_position++;
            }
            else {
                if (right_current >= right_max) right_max = right_current;
                else ret += (right_max - right_current);
                right_position--;
            }
        }
        return ret;
    }
};