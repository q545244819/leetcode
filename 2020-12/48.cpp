class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    // 思路：模拟
    // 1.先做对角线交换
    // 2.再做每一行开头和末尾交换
    int n = matrix.size();

    if (n == 0)
      return;

    // 1
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j <= i; j++)
      {
        swap(matrix[i][j], matrix[j][i]);
      }
    }

    // 2
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n / 2; j++)
      {
        swap(matrix[i][j], matrix[i][n - j - 1]);
      }
    }
  }
};