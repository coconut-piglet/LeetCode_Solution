class Solution {
public:
    void sortColors(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }
private:
    void quickSort(vector<int>& nums, int begin, int end) {
        if (begin >= end) return;
        int key = nums[begin];
        int front = begin + 1;
        int back = end;
        while (true) {
            while (nums[front] <= key) {
                if (front == end) break;
                front++;
            }
            while (nums[back] >= key) {
                if (back == begin) break;
                back--;
            }
            if (front < back) {
                swap(nums[front], nums[back]);
            }
            else {
                break;
            }
        }
        swap(nums[begin], nums[back]);
        quickSort(nums, begin, back - 1);
        quickSort(nums, back + 1, end);
    }
};