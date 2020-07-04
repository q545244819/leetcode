class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> S;

        S.push(-1);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                S.push(i);
            } else {
                S.pop();
                if (S.empty()) {
                    S.push(i);
                } else {
                    ans = max(ans, i - S.top());
                }
            }
        }

        return ans;
    }
};