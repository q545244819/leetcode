class Solution {
public:
    unordered_set<string> S;
    vector<string> permutation(string s) {
        vector<string> ans;

        dfs(s, 0);

        for (unordered_set<string>::iterator it = S.begin(); it != S.end(); it++) ans.push_back(*it);

        return ans;
    }

    void dfs (string s, int i) {
        if (i >= s.length()) {
            S.insert(s);
            return;
        }

        for (int j = i; j < s.length(); j++) {
            swap(s[i], s[j]);
            dfs(s, i + 1);
            swap(s[i], s[j]);
        }
    }
};