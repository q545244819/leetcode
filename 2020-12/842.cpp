class Solution {
public:
    vector<int> res;
    vector<int> splitIntoFibonacci(string S) {
        // 思路：回溯算法
        // 需要特别注意判断 F[i] + F[i + 1] = F[i + 2] 和划分子序列转成整数会溢出 int 整型的情况。
        int n = S.size();
        if (n < 2)
            return {};
        dfs(S, 0);
        return res;
    }
    bool dfs(string& S, int begin) {
        int n = S.size();
        if (begin >= n && res.size() > 2)
            return true;

        long cur = 0;
        int len = 0;

        for (int i = begin; i < n; i++) {
            // 跳过前导 0 的情况。
            if (len > 0 && cur == 0)
                break;
            
            cur *= 10;
            cur += S[i] - '0';

            // 判断划分的子序列整数是否溢出
            if (cur >= INT_MAX)
                break;

            if (res.size() < 2) {
                res.push_back(cur);
                if (dfs(S, i + 1))
                    return true;
                res.pop_back();
            } else {
                int n = res.size();
                long m = (long)res[n - 2] + (long)res[n - 1]; // 处理溢出情况
                if (m < INT_MAX && m == cur) {
                    res.push_back(cur);
                    if (dfs(S, i + 1))
                        return true;
                    res.pop_back();
                }
            }

            len++;
        }

        return false;
    }
};