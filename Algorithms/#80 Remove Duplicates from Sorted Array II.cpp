class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size <= 2) return size;
        
        int prv = 0;
        int src = 2;
        int dst = 2;
        
        while (src < size) {
            if (nums[src] != nums[prv]) {
                nums[dst] = nums[src];
                dst++;
                prv++;
            }
            src++;
        }
        
        size = dst;
        
        return size;
    }
};