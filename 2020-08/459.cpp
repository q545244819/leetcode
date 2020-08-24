class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        if (n == 0) return false;
        if (n == 1) return false;

        bool ans = false;

        // 取 0 ～ n/2 长度的字符串前缀，判断该前缀拼接 n / k 次后是否与结果字符串相同
        for (int k = 1; k <= n / 2; k++) {
            // 跳过不可能组成结果的子字符串数量
            if (n % k) continue;
            // 截取子字符串拼接
            string p = s.substr(0, k);
            string t = p;
            while (t.size() < n) {
                t += p;
            }
            // 判断是否能够组成结果字符串
            if (t == s)
                return true;
        }

        return false;
    }
};