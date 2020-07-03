class Solution {
public:
    set<string> S;
    vector<string> permutation(string s) {
        vector<int> book(s.length(), 0);
        vector<string> ans;
        dfs(book, s, 0, "");
        for (set<string>::iterator it = S.begin(); it != S.end(); it++) ans.push_back(*it);
        return ans;
    }

    void dfs (vector<int>& book, string s, int step, string str) {
        if (step >= s.length()) {
            S.insert(str);
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            if (!book[i]) {
                book[i] = 1;
                dfs(book, s, step + 1, str + s[i]);
                book[i] = 0;
            }
        }
    }
};