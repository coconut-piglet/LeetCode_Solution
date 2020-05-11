class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 2) return size;
        
        int dst, src, crt, prev;
        bool dup;
        
        dst = 1;
        src = 1;
        prev = nums[0];
        dup = false;
        
        while (src < size) {
            crt = nums[src];
            if (crt == prev) {
                if (dup) {
                    src++;
                    continue;
                }
                dup = true;
            }
            else {
                prev = crt;
                dup = false;
            }
            nums[dst] = crt;
            dst++;
            src++;
        }
        size = dst;
        
        return size;
    }
};