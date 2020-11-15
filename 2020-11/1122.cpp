class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> memo;
        vector<int> ans;
        int len = 0;

        for (const int& i : arr1)
            memo[i]++;
        
        for (const int& i : arr2) {
            len += memo[i];
            for (int j = 0; j < memo[i]; j++)
                ans.push_back(i);
            memo.erase(i);
        }

        for (const auto& item : memo) {
            for (int i = 0; i < item.second; i++)
                ans.push_back(item.first);
        }

        sort(ans.begin() + len, ans.end());

        return ans;
    }
};