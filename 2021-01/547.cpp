class Solution
{
public:
  vector<bool> visited;
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int n = isConnected.size();
    int colors = 0;

    if (n == 0)
      return 0;

    visited.resize(n);

    for (int i = 0; i < n; i++)
      if (!visited[i])
        dfs(i, ++colors, isConnected);

    return colors;
  }
  void dfs(int n, int color, vector<vector<int>> &isConnected)
  {
    visited[n] = color;

    for (int i = 0; i < isConnected.size(); i++)
    {
      if (i != n && isConnected[n][i] == 1 && !visited[i])
        dfs(i, color, isConnected);
    }
  }
};