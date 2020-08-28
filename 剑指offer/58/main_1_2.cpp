class Solution {
public:
    string reverseWords(string s) {
        // 思路：反转
        // 1.首先将整个字符串反转
        // 2.将字符串内对单词反转，并且放到栈中
        // 3.拼接字符串，输出正确答案
        int n = s.length();

        reverseStr(s, 0, n - 1); // 1
        
        int i = 0, j = 0;
        vector<string> S;
        
        while (i < n) {
            if (s[i] == ' ') {
                if (i - 1 >= 0 && s[i - 1] != ' ') { // 2
                    reverseStr(s, j, i - 1);
                    S.push_back(s.substr(j, i - j));
                }
                j = i + 1;
            }
            i++;
        }
        if (i > j) { // 2
            reverseStr(s, j, i - 1);
            S.push_back(s.substr(j, i - j));
        }

        string ans = "";
        for (int i = 0; i < S.size(); i++) { // 3
            ans += S[i];
            if (i < S.size() - 1)
                ans += " ";
        }

        return ans;
    }
    void reverseStr (string& s, int l, int r) {
        while (l < r)
            swap(s[l++], s[r--]);
    }
};