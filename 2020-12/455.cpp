class Solution
{
public:
  int findContentChildren(vector<int> &g, vector<int> &s)
  {
    // 思路：排序+双指针
    if (g.size() == 0 || s.size() == 0)
      return 0;

    int ans = 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int p1 = 0, p2 = 0;

    while (p1 < g.size() && p2 < s.size())
    {
      if (g[p1] <= s[p2])
      {
        p1++;
        ans++;
      }
      p2++;
    }

    return ans;
  }
};