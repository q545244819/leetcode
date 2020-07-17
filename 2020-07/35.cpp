class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m = l;

        while (l <= r) {
            m = l + ((r - l) >> 1);

            if (nums[m] == target) return m;
            else if (nums[m] > target) r = m - 1;
            else l = m + 1;
        }

        return l;
        // return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};