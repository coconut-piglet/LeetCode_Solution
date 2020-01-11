class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size, size1, size2, ptr, ptr1, ptr2;
        double ret;
        size1 = nums1.size();
        size2 = nums2.size();
        size = size1 + size2;
        ptr1 = 0;
        ptr2 = 0;
        ptr = 0;
        int merged[size];
        while (ptr1 < size1 && ptr2 < size2) {
            if (nums1[ptr1] < nums2[ptr2]) {
                merged[ptr] = nums1[ptr1];
                ptr1++;
            }
            else {
                merged[ptr] = nums2[ptr2];
                ptr2++;
            }
            ptr++;
        }
        if (ptr1 == size1) {
            for (int i = ptr; i < size; i++) {
                merged[i] = nums2[ptr2];
                ptr2++;
            }
        }
        else {
            for (int i = ptr;i < size; i++) {
                merged[i] = nums1[ptr1];
                ptr1++;
            }
        }
        if (size % 2 == 0) {
            ret = (double(merged[size / 2 - 1]) + double(merged[size / 2])) / 2;
        }
        else {
            ret = double(merged[(size - 1) / 2]);
        }
        return ret;
    }
};