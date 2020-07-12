class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 本质还是O(n)
        int l = 0, r = nums.size() - 1, m = l, res = 0;
        
        if (nums.size() == 0) return 0;
        if (nums[l] == nums[r] && nums[l] == target) return r - l + 1;

        while (l <= r) {
            m = l + ((r - l) >> 1);

            if (nums[m] == target) {
                for (int i = l; i <= r; i++)
                    if (nums[i] == target) res++;
                break;
            }

            if (nums[m] <= target) l = m + 1;
            else r = m - 1;
        }

        return res;
    }
};