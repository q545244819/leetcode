class Solution
{
public:
  string removeDuplicateLetters(string s)
  {
    // 思路：贪心算法
    // 按顺序访问每一个字符，若当前字符比栈顶顶字符小，且栈顶顶字符在该位置后出现的次数大于等于 1，则把栈顶字符弹出
    // 最后都把当前字符入栈，且维护该字符到当前位置到末尾所出现到次数
    // 若当前字符已经在栈中，则只需要维护该字符到当前位置到末尾所出现到次数就行了。
    if (s.length() == 0)
      return "";

    vector<int> memo(27, 0);
    string ans = "";
    vector<char> sstack;
    vector<int> used(27, false);

    for (const char &ch : s)
      memo[ch - 'a']++;

    for (const char &ch : s)
    {
      if (used[ch - 'a'])
      {
        memo[ch - 'a']--;
        continue;
      }

      while (sstack.size() && ch < sstack.back() && memo[sstack.back() - 'a'] >= 1)
      {
        used[sstack.back() - 'a'] = false;
        sstack.pop_back();
      }

      sstack.push_back(ch);
      used[ch - 'a'] = true;
      memo[ch - 'a']--;
    }

    for (const char &ch : sstack)
      ans += ch;

    return ans;
  }
};