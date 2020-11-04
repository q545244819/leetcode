class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // 思路：三种情况，第一种小区间的右区间都在左端点之前，第二种情况，左端点在某个小区间内，第三种情况小区间的左区间都在右端点后
        // 重要：记得画图，记得画图，记得画图

        int n = intervals.size(), i = 0;
        vector<vector<int>> ans;
        
        // 1
        for (; i < n && intervals[i][1] < newInterval[0]; i++)
            ans.push_back(intervals[i]);
        
        // 2
        for (; i < n && intervals[i][0] <= newInterval[1]; i++) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }

        ans.push_back(newInterval);

        // 3
        for (; i < n; i++)
            ans.push_back(intervals[i]);

        return ans;
    }
};