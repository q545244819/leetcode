class Solution
{
public:
  vector<vector<int>> largeGroupPositions(string s)
  {
    vector<vector<int>> ans;
    if (s.length() == 0)
      return {};

    char ch = s[0];
    int begin = 0;

    s += '@';

    for (int i = 1; i < s.length(); i++)
    {
      if (s[i] == ch)
        continue;

      if (i - begin >= 3)
        ans.push_back({begin, i - 1});

      ch = s[i];
      begin = i;
    }

    return ans;
  }
};