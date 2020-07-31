class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        int ans = -1;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == i) {
                ans = i;
                break;
            }

        return ans;
    }
};