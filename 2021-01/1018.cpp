class Solution
{
public:
  vector<bool> prefixesDivBy5(vector<int> &A)
  {
    // 思路：仅关心对应位置的十进制数最低位是否为 0 或者 5
    vector<bool> ans;

    int num = 0;

    for (int i = 0; i < A.size(); i++)
    {
      // 二进制转十进制
      num <<= 1;
      num += A[i];
      // 只保留十进制最低位
      num %= 10;
      ans.push_back(num % 5 == 0);
    }

    return ans;
  }
};