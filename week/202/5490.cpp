class Solution {
public:
    unordered_map<int, int> memo;
    int minDays(int n) {
        return dfs(n);
    }
    int dfs (int n) {
        if (n == 0) return memo[0] = 0;
        if (n == 1) return memo[1] = 1;
        if (n == 2) return memo[2] = 2;
        if (memo.find(n) != memo.end()) return memo[n];
        
        // 假设橘子数量是 n
        // 若橘子数量不是 2 的倍数的话，那么先需要吃掉 n % 2 个橘子/天（同时吃一个需要一天）
        // 若橘子数量不是 3 的倍数的话，同理
        // m = 取整(n / 2)
        // dfs(n / 2): 吃掉 n / 2 个橘子需要的最小天数
        // n % 2: 将 n 吃到偶数的 m 需要多少天
        return memo[n] = 1 + min(dfs(n / 2) + n % 2, dfs(n / 3) + n % 3);
    }
};