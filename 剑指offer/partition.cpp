int partition(vector<int> &nums, int l, int r)
{
  int index = l + (r - l) / 2;
  swap(nums[index], nums[r]);
  int small = l;

  for (index = l; index < r; index++)
  {
    if (nums[index] < nums[r])
    {
      swap(nums[index], nums[small++]);
    }
  }

  swap(nums[small], nums[index]);

  return small;
}