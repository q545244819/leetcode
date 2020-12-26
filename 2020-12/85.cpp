class Solution
{
public:
  int maximalRectangle(vector<vector<char>> &matrix)
  {
    // 思路：从 84 题柱状图中最大的矩形思路开始扩展
    // 每一行表示 1 的列表示柱状的高度，若是 0，则柱状高度为 0，若是 1 则高度是上一个列的高度 + 1
    // 然后对每一行计算“柱状图中最大的矩形”，保存最大的面积
    int n = matrix.size();
    if (n == 0)
      return 0;
    int m = matrix[0].size();
    int ans = 0;
    vector<int> t(m, 0);

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        t[j] = matrix[i][j] == '0' ? 0 : t[j] + 1;
      }
      ans = max(ans, rectangles_from_histogram(t));
    }

    return ans;
  }

  int rectangles_from_histogram(vector<int> &H)
  {
    int ans = 0;
    stack<pair<int, int>> S;
    auto H2 = H;
    H2.push_back(-1e9);

    for (int right = 0; right < H2.size(); right++)
    {
      int x = H2[right];
      int left = right;
      while (!S.empty() && S.top().second >= x)
      {
        auto top = S.top();
        S.pop();
        left = top.first;
        int rect = top.second * (right - top.first);
        if (rect > ans)
          ans = rect;
      }
      S.push({left, x});
    }

    return ans;
  }
};