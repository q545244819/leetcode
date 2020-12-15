class Solution
{
public:
  int monotoneIncreasingDigits(int N)
  {
    int i = 1;
    int ans = N;

    while (i <= ans / 10)
    {
      int n = ans / i % 100;
      i *= 10;
      // 高位：n / 10
      // 低位：n % 10
      // 若低位比高位高，则计算一个最接近 ans 且单调递增的数
      // 例如：输入 332，高位 3，低位 2，ans = 332 / 100 * 100 - 1 = 299
      if (n / 10 > n % 10)
        ans = ans / i * i - 1;
    }

    return ans;
  }
};