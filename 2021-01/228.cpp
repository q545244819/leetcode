class Solution
{
public:
  vector<string> summaryRanges(vector<int> &nums)
  {
    int n = nums.size();

    if (n == 0)
      return {};

    vector<string> ans;
    int begin = nums[0];

    nums.push_back(1e9);

    for (int i = 1; i <= n; i++)
    {
      // 坑：要转 long
      if ((long)nums[i] - (long)nums[i - 1] != 1)
      {
        if (begin != nums[i - 1])
          ans.push_back(to_string(begin) + "->" + to_string(nums[i - 1]));
        else
          ans.push_back(to_string(nums[i - 1]));

        begin = nums[i];
      }
    }

    return ans;
  }
};