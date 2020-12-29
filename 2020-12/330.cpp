class Solution
{
public:
  int minPatches(vector<int> &nums, int n)
  {
    // 题解：https://leetcode-cn.com/problems/patching-array/solution/patching-array-tan-lan-suan-fa-by-jyd/
    int i = 0, ans = 0;
    // 在 [1, n) 区间内添加数字 m, 且 m <= n，则可以得到新区间 [1, n + m)
    // 可以通过添加 n，让区间 [1, n), 扩大至 [1, 2n)
    // 从 [1,1) 区间开始，不断扩大右开区间，直到大于等于 n
    long right = 1;

    while (right <= n)
    {
      if (i < nums.size() && nums[i] <= right)
      { // 使用 nums 数组中的数, 扩大数组，得到新区间[1, right + nums[i])
        right += nums[i++];
      }
      else
      { // nums 数组中的数已经使用完了，但是区间还没有覆盖 [1, n]，所以直接添加一个 right 元素到 nums 数组中，扩大一倍目前的范围得到 [1, 2right)
        right += right;
        ans++; // 往 nums 数组中添加了元素 right，所以需要添加的数加 1
      }
    }

    return ans;
  }
};