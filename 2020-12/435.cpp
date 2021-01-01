class Solution
{
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals)
  {
    // 思路：贪心算法
    // 将间隔数组的右边界升序排序，计算最多有多少个区间可以组合一起且不重叠
    // “原区间数组”数量减去“最多不重叠区间”数量就是最少需要删除区间数量
    // 以后可以尝试反过来想
    sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {
      return a[1] < b[1];
    });

    int n = intervals.size();

    if (n == 0)
      return 0;

    int ans = 1;
    int right = intervals[0][1];

    for (int i = 1; i < n; i++)
    {
      auto cur = intervals[i];

      if (cur[0] < right)
        continue;

      right = cur[1];
      ans++;
    }

    return n - ans;
  }
};