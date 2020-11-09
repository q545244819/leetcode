class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // 思路：求出每个点的欧几里得距离且排序后再取出钱 K 个点。
        int n = points.size();
        vector<pair<int, int>> data;
        vector<vector<int>> ans;

        if (n == 0)
            return ans;

        for (int i = 0; i < n; i++) {
            auto point = points[i];
            data.push_back({ point[0] * point[0] + point[1] * point[1], i });
        }

        sort(data.begin(), data.end(), [](const auto& p1, const auto& p2) {
            return p1.first < p2.first;
        });

        for (int i = 0; i < K; i++)
            ans.push_back(points[data[i].second]);

        return ans;
    }
};