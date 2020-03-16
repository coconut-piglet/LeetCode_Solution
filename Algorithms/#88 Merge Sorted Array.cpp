class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int head = nums1.size();
        head--;
        m--;
        n--;
        while (m >= 0 && n >= 0) {
            if (nums1[m] > nums2[n]) {
                nums1[head] = nums1[m];
                m--;
            }
            else {
                nums1[head] = nums2[n];
                n--;
            }
            head--;
        }
        if (n >= 0) {
           for (int i = 0; i <= n; i++) {
               nums1[i] = nums2[i];
           }
        }
        return;
    }
};