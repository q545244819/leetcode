class Solution
{
public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> ans(numRows, vector<int>());

    if (numRows == 0)
      return {};

    ans[0] = {1};

    if (numRows == 1)
      return ans;

    ans[1] = {1, 1};

    for (int i = 2; i < numRows; i++)
    {
      ans[i].push_back(1);
      for (int j = 1; j <= i - 1; j++)
      {
        ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
      }
      ans[i].push_back(1);
    }

    return ans;
  }
};