class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 思路：排序+区间合并，合并后的区间数量为答案
        int n = points.size();
        
        if (n == 0)
            return 0;
        
        sort(points.begin(), points.end(), [](const auto& a, const auto& b) {
            if (a[0] != b[0])
                return a[0] < b[0];
            else
                return a[1] < b[1];
        });

        int ans = 1;
        int xs = points[0][0], xe = points[0][1];

        for (int i = 1; i < n; i++) {
            if (points[i][0] <= xe) {
                xs = max(xs, points[i][0]);
                xe = min(xe, points[i][1]);
            } else {
                ans++;
                xs = points[i][0];
                xe = points[i][1];
            }
        }

        return ans;
    }
};