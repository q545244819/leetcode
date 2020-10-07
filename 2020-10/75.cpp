class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 思路：三指针移动
        // 第一个指针只管扫描元素
        // 第二个指针表示红色需要在数组左边的位置，初始值是 0
        // 第三个指针表示蓝色需要在数组右边的位置，初始值是 n - 1
        int n = nums.size();
        int i = 0; // 1
        int l = 0; // 2
        int r = n - 1; // 3
        while (i <= r) {
            if (nums[i] == 0) {
                if (i > 0)
                    swap(nums[l++], nums[i]); // 当前位置的 0 需要交换到正确的位置上
                else
                    l++; // 第 0 位的位置上是 0，l 直接往后移动，下一个 0 可能需要交换的位置
                i++;
            } else if (nums[i] == 1) { // 忽略白色
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[r]); // 当前位置的 2 需要交换正确位置上
                r--; // 交换后表示右边已经被 2 占住了，所以 r 需要往前移动，下一个 2 可能需要交换的位置
            }
        }
    }
};