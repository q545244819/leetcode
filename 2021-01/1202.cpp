class Solution
{
public:
  vector<int> parent;
  vector<int> rank;
  string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
  {
    // 思路：并查集+哈希表+优先队列
    // 首先将 pairs 中的所有 pair 都合并起来，找出同属一颗树的所有下标值
    // 再者根据同属一个树的下标值所表示的字符排序，然后遍历字符串的每一位，从该下标表示的树中取一个最小的字母
    int n = s.length();

    if (n == 0)
      return "";

    parent.resize(n);
    rank.resize(n);

    for (int i = 0; i < n; i++)
      parent[i] = i;

    string ans;

    for (const auto &pair : pairs)
      unite(pair[0], pair[1]);

    map<int, priority_queue<char, vector<char>, greater<char>>> mmap;

    for (int i = 0; i < n; i++)
    {
      int root = find(i);
      mmap[root].push(s[i]);
    }

    for (int i = 0; i < n; i++)
    {
      int root = find(i);

      ans += mmap[root].top();
      mmap[root].pop();
    }

    return ans;
  }
  int find(int x)
  {
    if (x != parent[x])
      parent[x] = find(parent[x]);
    return parent[x];
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