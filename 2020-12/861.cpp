class Solution
{
public:
  int matrixScore(vector<vector<int>> &A)
  {
    // 思路：贪心算法
    // 1.首先将第一列都变成 1，扫描第一列为 0 的数，反转它所在的行，这样保证当前行目前的二进制数最大
    // 2.扫描 1 ～ m 列的 0 的数量和 1 的数量，若 0 的数量大于等于 1 的数量，则反转当前列
    // 重复以上步骤直到扫描到最后一列退出
    // 3.最后计算二进制相加的十进制结果，并返回
    int n = A.size();
    if (n == 0)
      return 0;
    int m = A[0].size();
    // 1
    for (int i = 0; i < n; i++)
    {
      if (A[i][0] == 0)
      {
        for (int j = 0; j < m; j++)
          A[i][j] = A[i][j] == 1 ? 0 : 1;
      }
    }
    // 2
    for (int i = 0; i < m; i++)
    {
      int res = 0;
      for (int j = 0; j < n; j++)
        if (A[j][i] == 0)
          res++;
      if (res >= n - res)
        for (int k = 0; k < n; k++)
          A[k][i] = A[k][i] == 1 ? 0 : 1;
    }
    // 3
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
      int res = 0;
      int idx = 1;
      for (int j = m - 1; j >= 0; j--)
      {
        res += A[i][j] * idx;
        idx *= 2;
      }
      ans += res;
    }

    return ans;
  }
};