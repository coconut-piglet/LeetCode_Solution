class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        
        if (size == 0) return 0;
        if (size == 1) return heights[0];
        
        int maxArea, height, width, area, tmp;
        stack<int> prev;
        
        maxArea = 0;
        heights.push_back(0);
        size++;
        
        for (int i = 0; i < size; i++) {
            if (prev.empty()) {
                prev.push(i);
                continue;
            }
            
            int *crtHeight = &heights[i];
            int *prvHeight = &heights[prev.top()];
            
            if (*crtHeight > *prvHeight) {
                prev.push(i);
                continue;
            }
            
            if (*crtHeight < *prvHeight) {
                while (!prev.empty()) {
                    tmp = prev.top();
                    height = heights[tmp];
                    if (height < *crtHeight) {
                        tmp = i - width;
                        break;
                    }
                    width = i - tmp;
                    area = height * width;
                    maxArea = area > maxArea ? area : maxArea;
                    prev.pop();
                }
                prev.push(tmp);
                heights[tmp] = *crtHeight;
            }
        }
        return maxArea;
    }
};