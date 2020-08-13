class Solution {
public:
    string addStrings(string num1, string num2) {
        // 特殊样例判断
        if (num1.length() == 0) return num2;
        if (num2.length() == 0) return num1;

        // 反转字符串，方便实现加法
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // 保证 num1 字符串的长度大于等于 num2 字符串的长度
        if (num1.length() < num2.length()) swap(num1, num2);

        int n = num1.length(), m = num2.length();

        // 临时数组存放结果
        vector<int> res(max(n, m) + 1, 0);
        int i = 0;
        string ans = "";

        while (i < n) {
            int num = num1[i] - '0';
            
            // 两数相同位置的数相加，若 i 的值超出了 num2 字符串的长度，则不相加
            if (i < m) num += num2[i] - '0';

            res[i] += num;
            
            // 处理进位
            if (res[i] >= 10) {
                res[i + 1] += 1;
                res[i] %= 10;
            }

            i++;
        }

        bool skipZero = false;

        // 忽略前导 0
        for (int i = res.size() - 1; i >= 0; i--) {
            // 注意若个位是 0 的话，也要输出 0
            if ((res[i] > 0 || i == 0) && !skipZero)
                skipZero = true;
            if (skipZero)
                ans += res[i] + '0';
        }

        return ans;
    }
};