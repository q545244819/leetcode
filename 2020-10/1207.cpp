class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // 思路：先对数组进行排序方便统计相同数字出现对次数，最后把出现的次数存入数组当中，当出现两个相同的次数返回 false，否则返回 true
        vector<bool> memo(1005, false);
        int n = arr.size();

        if (n == 0)
            return true;

        sort(arr.begin(), arr.end());

        arr.push_back(INT_MAX);

        int begin = -1;

        for (int i = 0; i < n; i++) {
            if (arr[i] != arr[i + 1]) {
                int res = i - begin;
                if (!memo[res]) {
                    begin = i;
                    memo[res] = true;
                }
                else
                    return false;
            }
        }

        return true;
    }
};