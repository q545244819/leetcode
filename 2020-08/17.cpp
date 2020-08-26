class Solution {
public:
    vector<string> a;
    vector<string> ans;
    vector<string> letterCombinations(string d) {
        if (d.length() == 0) return ans;
        a = vector<string>(10);
        a[2] = "abc";
        a[3] = "def";
        a[4] = "ghi";
        a[5] = "jkl";
        a[6] = "mno";
        a[7] = "pqrs";
        a[8] = "tuv";
        a[9] = "wxyz";
        dfs(0, "", d);
        return ans;
    }
    void dfs (int idex, string res, string& d) {
        if (idex >= d.length()) {
            ans.push_back(res);
            return;
        }

        for (int i = 0; i < a[d[idex] - '0'].length(); i++) {
            dfs(idex + 1, res + a[d[idex] - '0'][i], d);
        }
    }
};