class Solution {
public:
    int minimumOneBitOperations(int n) {
        // 思路：还是找规律
        if (n == 0)
            return 0;
        // 获取最左边第一个为 1 的位置
        int pos = 32 - __builtin_clz(n) - 1;
        return (1 << (pos + 1)) - 1 - minimumOneBitOperations(n ^ (1 << pos));
    }
};