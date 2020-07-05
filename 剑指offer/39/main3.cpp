class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 时间复杂度 O(n)
        // 空间复杂度 O(1)
        int ans = nums[0], cnt = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (ans == nums[i])
                cnt++;
            else
                cnt--;

            if (cnt == 0) {
                ans = nums[i];
                cnt = 1;
            }
        }

        return ans;
    }
};