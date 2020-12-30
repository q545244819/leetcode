class Solution
{
public:
  int lastStoneWeight(vector<int> &stones)
  {
    priority_queue<int, vector<int>, less<int>> maxHeap;

    for (const int &i : stones)
      maxHeap.push(i);

    while (maxHeap.size() > 1)
    {
      int x = maxHeap.top();
      maxHeap.pop();
      int y = maxHeap.top();
      maxHeap.pop();

      if (x != y)
        maxHeap.push(abs(x - y));
    }

    if (!maxHeap.empty())
      return maxHeap.top();

    return 0;
  }
};