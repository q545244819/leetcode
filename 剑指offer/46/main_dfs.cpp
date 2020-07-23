class Solution {
public:
    int ans = 0;
    vector<char> res;
    int translateNum(int num) {
        // 递归
        dfs(0, to_string(num));
        return ans;
    }
    void dfs (int i, string num) {
        if (i >= num.length()) {
            ans++;
            return;
        }
        
        dfs(i + 1, num);
        int n = ((num[i] - '0') * 10 + (num[i + 1] - '0'));
        if (i + 1 < num.length() && num[i] > '0' && n < 26)
            dfs(i + 2, num);
    } 
};