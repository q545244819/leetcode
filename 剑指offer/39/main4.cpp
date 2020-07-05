class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 使用 partition 算法，会修改原来的数组
        // 时间复杂度 O(n)
        // 空间复杂度 O(1)
        int index = partition(nums, 0, nums.size() - 1);
        int mid = nums.size() / 2;
        int l = 0, r = nums.size() - 1;

        while (index != mid) {
            if (index > mid) {
                r = index - 1;
                index = partition(nums, l, r);
            } else {
                l = index + 1;
                index = partition(nums, l, r);
            }
        }
        
        return nums[mid];
    }

    int partition (vector<int>& nums, int l, int r) {
        int index = l + (r - l) / 2;
        swap(nums[index], nums[r]);
        int small = l;

        for (index = l; index < r; index++) {
            if (nums[index] < nums[r]) {
                swap(nums[index], nums[small++]);
            }
        }

        swap(nums[small], nums[index]);

        return small;
    }
};