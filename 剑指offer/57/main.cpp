class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 双指针
        int l = 0, r = nums.size() - 1;
        while (nums[l] + nums[r] != target) {
            if (nums[l] + nums[r] > target)
                r--;
            else
                l++;
        }
        return {nums[l], nums[r]};
    }
};