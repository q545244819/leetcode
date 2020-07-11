class Solution {
public:
    int countDigitOne(int n) {
        vector<long> memo;
        long ans = 0;
        int len = getLength(n);

        memo.push_back(0);

        // 设置每一个位出现的 1 的次数。比如
        // 0 位数出现 0 次
        // 1 位数（0～9）出现 1 次
        // 2 位数（0～99）出现 20 次
        // 以此类推
        // 公式: memo[i] = pow(10, i - 1) + memo[i - 1] * 10
        for (int i = 1; i < len; i++)
            memo.push_back((int)pow(10, i - 1) + memo[i - 1] * 10);
        
        while (n) {
            len = getLength(n);
            int product = (int)pow(10, len - 1);
            int first = n / product;
            
            // 当前 n 的最高位是 1 时
            // 1000..~1xx.. 中就有 xx + 1 个出现 1 的数量
            // first * memo[len - 1] 是求删除最高位数字后的数字出现 1 的数量
            if (first == 1)
                ans += (n % product) + 1 + first * memo[len - 1];
            else
                ans += product + first * memo[len - 1];

            n = n % (first * product);
        }

        return ans;
    }

    int getLength (int n) {
        int res = 0;
        
        while (n) {
            res++;
            n /= 10;
        }

        return res;
    }
};