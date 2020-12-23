class Solution
{
public:
  int firstUniqChar(string s)
  {
    vector<int> memo(27, 0);

    for (const char &ch : s)
      memo[ch - 'a']++;

    for (int i = 0; i < s.length(); i++)
      if (memo[s[i] - 'a'] == 1)
        return i;

    return -1;
  }
};