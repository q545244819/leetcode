class Solution
{
public:
  char findTheDifference(string s, string t)
  {
    // 思路：位运算，两个相同的数异或结果为 0
    int p = 0;

    for (int i = 0; i < s.length(); i++)
    {
      p ^= s[i];
      p ^= t[i];
    }

    p ^= t[s.length()];

    return p;
  }
};