class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int n = A.size();

        if (n == 0)
            return {};
        
        vector<string> ans;
        vector<vector<int>> chars(n, vector<int>(27, 0));

        for (int i = 0; i < n; i++)
            for (char c : A[i])
                chars[i][c - 'a']++;

        for (int i = 0; i < 27; i++) {
            int found = true;
            int len = 105;
            for (int j = 0; j < n; j++) {
                len = min(len, chars[j][i]);
                if (chars[j][i] == 0) {
                    found = false;
                    break;
                }
            }
            if (found) {
                for (int j = 0; j < len; j++) {
                    char res = i + 'a';
                    ans.push_back(string(1, res));
                }
            }
        }

        return ans;
    }
};