class Solution
{
public:
  vector<int> parent;
  vector<int> rank;
  vector<int> findRedundantConnection(vector<vector<int>> &edges)
  {
    // 思路：类似最小生成树（克鲁斯卡尔）算法中，添加一条边后，图是否出现回路的情况。
    // 使用并查集

    vector<int> ans;
    int n = 0;

    for (const auto &edge : edges)
      n = max(n, max(edge[0], edge[1]));

    if (n == 0)
      return {};

    parent.resize(n + 1);
    rank.resize(n + 1);

    for (int i = 0; i <= n; i++)
      parent[i] = i;

    for (const auto &edge : edges)
    {
      if (!same(edge[0], edge[1]))
        unite(edge[0], edge[1]);
      else
        ans = edge;
    }

    return ans;
  }
  int find(int x)
  {
    if (x != parent[x])
      parent[x] = find(parent[x]);
    return parent[x];
  }
  int same(int x, int y)
  {
    return find(x) == find(y);
  }
  void unite(int x, int y)
  {
    int p1 = find(x);
    int p2 = find(y);

    if (rank[p1] < rank[p2])
    {
      parent[p1] = p2;
    }
    else
    {
      parent[p2] = p1;
      if (rank[p1] == rank[p2])
        rank[p1]++;
    }
  }
};