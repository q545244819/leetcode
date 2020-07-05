class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 时间复杂度O(n)
        // 空间复杂度O(n)
        int n = nums.size();
        unordered_map<int, int> M;
        
        for (int i = 0; i < n; i++) {
            M[nums[i]]++;

            if (M[nums[i]] > n / 2) return nums[i];
        }

        return INT_MIN;
    }
};