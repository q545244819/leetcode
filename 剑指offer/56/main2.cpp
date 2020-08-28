class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 思路：同数组中只出现两位数类似，将是十进制数转换成二进制数，且每一位相加。若当前位置的值能被 3 整除说明只出现一次的数的二进制表示在该位置上是 0，若不能被整除则表示该位置上是 1。
        // 1.统计二进制数每一位出现的次数
        // 2.判断该位出现的次数是否能被 3 整除，求出只出现一次数字的二进制表达
        // 3.二进制转十进制
        vector<int> res(32, 0);
        // 1
        for (int num : nums) {
            int j = 1;
            for (int i = 0; i < 31; i++) {
                res[i] += (num & j) != 0 ? 1 : 0;
                j <<= 1;
            }
        }
        int ans = 0;
        int n = 1;
        for (int i = 0; i < 31; i++) {
            // 2
            res[i] = res[i] % 3 == 0 ? 0 : 1;
            // 3
            ans += res[i] * n;
            n <<= 1;
        }
        return ans;
    }
};