class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> data;
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
            data.push_back({ nums[i], i });

        sort(data.begin(), data.end());

        for (int i = 0; i < n; i++) {
            int j = i;
            while (j > 0 && data[j].first == data[j - 1].first)
                j--;
            ans[data[i].second] = j;
        }

        return ans;
    }
};