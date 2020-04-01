class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // First Attempt
        // vector<vector<int>> ret;
        // int size = intervals.size();
        // if (size == 0) return ret;
        // vector<int> lowerBounds;
        // vector<int> upperBounds;
        // for (vector<int> interval : intervals) {
        //     lowerBounds.push_back(interval[0]);
        //     upperBounds.push_back(interval[1]);
        // }
        // sort(lowerBounds.begin(), lowerBounds.end());
        // sort(upperBounds.begin(), upperBounds.end());
        // int low = lowerBounds[0];
        // int high = upperBounds[size - 1];
        // vector<int> interval = {low, high};
        // for (int i = 1; i < size; i++) {
        //     if (upperBounds[i - 1] < lowerBounds[i]) {
        //         high = upperBounds[i - 1];
        //         interval[0] = low;
        //         interval[1] = high;
        //         ret.push_back(interval);
        //         low = lowerBounds[i];
        //     }
        // }
        // interval[0] = low;
        // interval[1] = upperBounds[size - 1];
        // ret.push_back(interval);
        // return ret;
        // Optimized Solution
        vector<vector<int>> ret;
        int size = intervals.size();
        if (size == 0) return ret;
        sort(intervals.begin(), intervals.end());
        int low = intervals[0][0], high = intervals[0][1];
        int currentLow, currentHigh;
        for (int i = 1; i < size; i++) {
            currentLow = intervals[i][0];
            currentHigh = intervals[i][1];
            if (currentLow > high) {
                ret.push_back({low, high});
                low = currentLow;
                high = currentHigh;
            }
            else {
                if (currentHigh > high) high = currentHigh;
            }
        }
        ret.push_back({low, high});
        return ret;
    }
};