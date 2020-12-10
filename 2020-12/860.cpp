class Solution
{
public:
  bool lemonadeChange(vector<int> &bills)
  {
    // 思路：贪心，由于金额的面额都是 5 的倍数，直接从大到小选择面额即可
    int five = 0, ten = 0;

    for (const int &i : bills)
    {
      if (i == 5)
      {
        five++;
      }
      else if (i == 10)
      {
        if (five == 0)
          return false;
        five--;
        ten++;
      }
      else if (i == 20)
      {
        if (ten)
        {
          ten--;
          if (five)
            five--;
          else
            return false;
        }
        else
        {
          if (five >= 3)
            five -= 3;
          else
            return false;
        }
      }
    }

    return true;
  }
};