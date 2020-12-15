class Solution
{
public:
  int monotoneIncreasingDigits(int N)
  {
    // 思路：贪心
    // 从低位往高位处理，若低位高位，则把低位到最低位都变成 9，高位减一，重复这个过程。
    string num = to_string(N);
    int n = num.length();

    for (int i = n - 1; i > 0; i--)
    {
      if (num[i] < num[i - 1])
      {
        int j = i;
        while (j < n)
          num[j++] = '9';
        num[i - 1]--;
      }
    }

    return stoi(num);
  }
};