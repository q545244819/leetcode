class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    deque<int> DQ(nums.begin(), nums.end());

    while (k--)
    {
      DQ.push_front(DQ.back());
      DQ.pop_back();
    }

    nums = vector<int>(DQ.begin(), DQ.end());
  }
};