class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 时间复杂度 O(nlogn)
        // 空间复杂度 O(1)
        sort(nums.begin(), nums.end());

        return nums[nums.size() / 2];
    }
};