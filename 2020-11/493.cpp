int L[50005], R[50005];

class Solution
{
public:
  int ans = 0;
  int reversePairs(vector<int> &nums)
  {
    // 思路：求逆序对的改版
    int n = nums.size();
    if (n == 0)
      return 0;
    mergeSort(0, n - 1, nums);
    return ans;
  }
  void mergeSort(int l, int r, vector<int> &nums)
  {
    if (l < r)
    {
      int m = l + (r - l) / 2;
      mergeSort(l, m, nums);
      mergeSort(m + 1, r, nums);

      // 统计下标对的数量
      int i = l;
      int j = m + 1;
      while (i <= m)
      {
        while (j <= r && (long long)nums[i] > 2 * (long long)nums[j])
          j++;
        ans += (j - m - 1);
        i++;
      }

      // 开始归并排序
      for (int i = l, j = 0; i <= m; i++, j++)
        L[j] = nums[i];
      for (int i = m + 1, j = 0; i <= r; i++, j++)
        R[j] = nums[i];

      int n1 = m - l + 1;
      int n2 = r - m;
      i = 0;
      j = 0;
      int k = l;

      while (i < n1 && j < n2)
      {
        if (L[i] < R[j])
          nums[k++] = L[i++];
        else
          nums[k++] = R[j++];
      }
      while (i < n1)
        nums[k++] = L[i++];
      while (j < n2)
        nums[k++] = R[j++];
    }
  }
};