class Solution {
public:
    int findNthDigit(int n) {
        int ans = n;
        if (n < 10) return ans;
        
        // i 表示数字长度，如 i = 2 表示 10~99 的范围，其中 j 表示这个范围内有 90 个数
        // 若 i = 3 则表示 100~999 的范围，其中 j 表示这个范围内有 900 个数
        // 以此类推。。。
        long i = 2, j = 90, t = 1;

        n -= 10;

        while (1) {
            // p 表示拥有 j 个数，且每一个数长度为 i，组成一个序列的总长度
            long p = i * j;
            t *= 10;

            if (p > n) {
                // 若当前 n 比 p 要小，则表示要找的数字在以 i 长度数字拼接成的序列中
                // 假设输入的 n 为 1001
                // 当前的 i 为 3、j 为 900 和 n 为 811。由于 811 < 2700，所以 1001 位在由 100~999 个数组成的序列中
                // 811 / 3 = 270 余 1
                // 所以第 1101 位的表示的是 100 + 270 = 370 的第 1 位数（从左边开始数）
                int m = n % i;
                int k = t + n / i;

                ans = to_string(k)[m] - '0';

                break;
            } else {
                // 若当前的 n 的长度比 p 要大，则表示要找的位置不属于 i 长度数字的范围内
                // 继续扩大 i 的值
                n -= p;
                i++;
                j *= 10;
            }
        }

        return ans;
    }
};