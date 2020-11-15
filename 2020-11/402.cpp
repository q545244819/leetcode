class Solution {
public:
    string removeKdigits(string num, int k) {
        // 思路：贪心算法
        int n = num.size();
        if (n == k)
            return "0";
        for (int i = 0; i < k; i++) {
            int idx = 0;
            // 从左往右扫描，找到比当前数值要大的下一位数值的下标，且删除该数
            for (int j = 1; j < num.length() && num[j] >= num[j - 1]; j++)
                idx = j;
            num.erase(num.begin() + idx);
            // 这里是处理前导 0 的情况
            while (num.length() > 1 && num[0] == '0')
                num.erase(num.begin());
        }
        return num;
    }
};