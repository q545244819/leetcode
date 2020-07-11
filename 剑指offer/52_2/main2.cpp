class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int m = l;

        while (l <= r) {
            m = l + (r - l) / 2;
            
            // 若当前 nums[m] > m 则表示缺少的数字在 l ~ m - 1 范围内
            // 否则在 m + 1 ~ r 的范围内
            // 若每一次 m 都等于 nums[m] 的话，l 会移动到 nums.size() 的位置，表示缺少 nums.size() 这个数字
            if (nums[m] > m)
                r = m - 1;
            else
                l = m + 1;
        }

        return l;
    }
};