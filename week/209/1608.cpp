class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int limit = nums.back();
        int n = nums.size();
        
        for (int i = 0; i <= limit; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] >= i)
                    cnt++;
            }
            if (cnt == i)
                return i;
        }
        
        return -1;
    }
};