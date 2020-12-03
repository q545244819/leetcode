class Solution
{
public:
  int countPrimes(int n)
  {
    // 思路：筛选法
    if (n == 0 || n == 1)
      return 0;
    vector<bool> memo(n + 1, true);
    int ans = n - 2;

    memo[0] = memo[1] = false;
    memo[2] = true;

    for (int i = 2; i <= sqrt(n); i++)
    {
      if (!memo[i])
        continue;
      for (int j = i + i; j < n; j += i)
      {
        if (memo[j])
        {
          ans--;
        }
        memo[j] = false;
      }
    }

    return ans;
  }
};