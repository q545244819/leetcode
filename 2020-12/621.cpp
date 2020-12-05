class Solution
{
public:
  int leastInterval(vector<char> &tasks, int n)
  {
    // 思路：模拟，先从出现最多的任务开始，下一个则是出现次大的任务开始，以此类推，每一轮一共做 n + 1 个任务，若没有那么多个任务则添加“待命”，最后统计数量。
    int len = tasks.size();

    if (n == 0)
      return len;

    vector<int> book(27, 0);
    vector<int> frequence; // 字频数组，存放 tasks 每一个字符存在的次数

    for (const char &ch : tasks)
      book[ch - 'A']++;

    for (const int &i : book)
      if (i > 0)
        frequence.push_back(i);

    sort(frequence.begin(), frequence.end(), greater<int>());

    int ans = 0;
    while (len)
    { // 开始模拟
      int j = 0;

      for (int i = 0; i < frequence.size() && j <= n; i++)
      {
        if (frequence[i] > 0)
        {
          len--;
          j++;
          ans++;
          frequence[i]--;
        }
        if (!len)
          break;
      }
      if (n >= j && len > 0) // 添加待命
        ans += n - j + 1;

      sort(frequence.begin(), frequence.end(), greater<int>()); // 需要将字频数组重新排序
    }

    return ans;
  }
};