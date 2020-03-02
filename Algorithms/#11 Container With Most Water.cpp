class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        int area = 0;
        int leftHeight, rightHeight;
        while (left < right) {
            leftHeight = height[left];
            rightHeight = height[right];
            area = (right - left) * min(leftHeight, rightHeight);
            maxArea = area > maxArea ? area : maxArea;
            if (left == right) {
                height[left + 1] > height[right - 1] ? left++ : right--;
                continue;
            }
            leftHeight > rightHeight ? right-- : left++;
        }
        return maxArea;
    }
};