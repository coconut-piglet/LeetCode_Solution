class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        
        if (size == 0) return 0;
        if (size == 1) return heights[0];
        
        int maxArea, height, width, area;
        stack<int> prev;
        
        maxArea = 0;
        heights.push_back(0);
        size++;
        
        for (int i = 0; i < size; i++) {
            if (prev.empty()) {
                prev.push(i);
                continue;
            }
            else if (heights[i] > heights[prev.top()]) {
                prev.push(i);
                continue;
            }
            else if (heights[i] < heights[prev.top()]) {
                while (!prev.empty()) {
                    height = heights[prev.top()];
                    if (height < heights[i]) {
                        break;
                    }
                    width = i - prev.top();
                    area = height * width;
                    maxArea = area > maxArea ? area : maxArea;
                    prev.pop();
                }
                prev.push(i - width);
                heights[i - width] = heights[i];
                continue;
            }
        }
        return maxArea;
    }
};