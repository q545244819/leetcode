class Solution
{
public:
  int largestPerimeter(vector<int> &A)
  {
    int n = A.size();

    if (n == 0)
      return 0;

    int ans = 0;
    sort(A.begin(), A.end(), [](const int &a, const int &b) {
      return a > b;
    });

    for (int i = 0; i < n - 2; i++)
    {
      if (A[i] < A[i + 1] + A[i + 2])
        return A[i] + A[i + 1] + A[i + 2];
    }
    return ans;
  }
};