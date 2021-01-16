class Solution
{
public:
  vector<int> parent;
  vector<int> rank;
  int removeStones(vector<vector<int>> &stones)
  {
    int n = stones.size();

    parent.resize(n);
    rank.resize(n);

    for (int i = 0; i < n; i++)
      parent[i] = i;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i == j)
          continue;
        if (stones[i][0] == stones[j][0])
        {
          unite(i, j);
        }
        if (stones[i][1] == stones[j][1])
        {
          unite(i, j);
        }
      }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
      if (find(i) != i)
        ans++;
    }

    return ans;
  }
  int find(int x)
  {
    if (x != parent[x])
      parent[x] = find(parent[x]);
    return parent[x];
  }
  bool same(int x, int y)
  {
    return find(x) == find(y);
  }
  void unite(int x, int y)
  {
    if (same(x, y))
      return;

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