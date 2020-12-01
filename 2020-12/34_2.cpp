class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    int n = nums.size();
    int l = 0, r = n - 1, m = l;

    while (l <= r)
    {
      m = l + (r - l) / 2;
      if (nums[m] == target)
      {
        int i = m, j = m;
        while (i > 0 && nums[i - 1] == target)
          i--;
        while (j < n - 1 && nums[j + 1] == target)
          j++;
        return {i, j};
      }
      else if (nums[m] < target)
      {
        l = m + 1;
      }
      else if (nums[m] > target)
      {
        r = m - 1;
      }
    }

    return {-1, -1};
  }
};