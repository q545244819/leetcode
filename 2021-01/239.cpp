class Solution
{
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k)
  {
    // 思路：单调队列（双端队列模拟）
    if (nums.size() == 0)
      return {};

    deque<int> Q;
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++)
    {
      while (!Q.empty() && nums[Q.back()] < nums[i])
      {
        Q.pop_back();
      }
      Q.push_back(i);
      if (i >= k - 1)
      {
        while (!Q.empty() && Q.front() <= i - k)
          Q.pop_front();
        if (!Q.empty())
          ans.push_back(nums[Q.front()]);
      }
    }

    return ans;
  }
};