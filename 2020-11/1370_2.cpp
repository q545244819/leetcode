class Solution {
public:
    string sortString(string s) {
        // 思路：记录字符出现的次数，根据字母表顺序拼接字符串，用过的字符需要将次数 - 1
        int n = s.length();
        vector<int> memo(27, 0);
        string ans = "";

        for (const char& ch : s)
            memo[ch - 'a']++;

        while (ans.length() != n) {
            for (int i = 0; i <= 25; i++) {
                if (memo[i]) {
                    memo[i]--;
                    ans += i + 'a';
                }
            }
            for (int i = 25; i >= 0; i--) {
                if (memo[i]) {
                    memo[i]--;
                    ans += i + 'a';
                }
            }
        }

        return ans;
    }
};