class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 举例分析观察规律
        if (nums.size() == 0) return 0;
        int sum = nums[0];
        int ans = sum;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] + sum < nums[i])
                sum = nums[i];
            else
                sum += nums[i];
            ans = max(ans, sum);
        }

        return ans;
    }
};