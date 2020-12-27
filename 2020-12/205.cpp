class Solution
{
public:
  bool isIsomorphic(string s, string t)
  {
    // 思路：哈希表
    if (s.length() != t.length())
      return false;

    unordered_map<char, char> memo;
    unordered_map<char, char> visted;

    for (int i = 0; i < s.length(); i++)
    {
      if (!memo.count(s[i]) && !visted.count(t[i]))
      {
        memo[s[i]] = t[i];
        visted[t[i]] = s[i];
        continue;
      }
      if (memo[s[i]] != t[i] || visted[t[i]] != s[i])
        return false;
    }

    return true;
  }
};