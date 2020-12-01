class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        if (n == 0)
            return {-1, -1};

        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);

        if (left == nums.end())
            return {-1, -1};
        if (*left != target)
            return {-1, -1};

        int i = distance(nums.begin(), left);
        int j = distance(nums.begin(), right) - 1;

        return {i, j};
    }
};