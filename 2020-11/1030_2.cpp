class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        // 思路：直接排序
        vector<vector<int>> ans;

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                ans.push_back({ i, j });

        sort(ans.begin(), ans.end(), [r0, c0](const auto& a, const auto& b) {
            return (abs(a[0] - r0) + abs(a[1] - c0)) < (abs(b[0] - r0) + abs(b[1] - c0));
        });

        return ans;
    }
};