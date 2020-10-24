class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        // 思路：动态规划，dp[i] 表示从 0～i需要的最少片段数
       const int INFTY = 1 << 21; // 设置一个不会超出 int 范围的相对较大值
       vector<int> dp(T + 1, INFTY);

       sort(clips.begin(), clips.end(), [](auto& a, auto& b) {
           return a[0] < b[0];
       });

       dp[0] = 0; // base case

       for (int i = 1; i <= T; i++) {
           for (auto& clip : clips) { // 枚举每一个片段，找到能够符合 0 ～ i 范围的片段
               if (i > clip[0] && i <= clip[1]) { // 表示当前 i 的位置在当前 clip 片段当中
                    // dp[clip[0]] + 1 表示 0～clip[0] 需要的最少片段数加上当前片段 clip
                    dp[i] = min(dp[i], dp[clip[0]] + 1);
               }
           }
       }

       return dp[T] == INFTY ? -1 : dp[T];
    }
};