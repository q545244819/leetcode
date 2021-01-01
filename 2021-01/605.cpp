class Solution
{
public:
  bool canPlaceFlowers(vector<int> &flowerbed, int n)
  {
    if (n == 0)
      return true;
    if (flowerbed.size() == 1 && flowerbed[0] == 0)
      return true;

    for (int i = 0; i < flowerbed.size(); i++)
    {
      if (flowerbed[i] == 1)
        continue;

      if (i == 0 && i + 1 < flowerbed.size() && flowerbed[i + 1] == 0)
        flowerbed[i] = 1, n--;
      else if (i == flowerbed.size() - 1 && i - 1 >= 0 && flowerbed[i - 1] == 0)
        flowerbed[i] = 1, n--;
      else if (i - 1 >= 0 && i + 1 < flowerbed.size() && flowerbed[i + 1] == 0 && flowerbed[i - 1] == 0)
        flowerbed[i] = 1, n--;
    }

    return n <= 0;
  }
};