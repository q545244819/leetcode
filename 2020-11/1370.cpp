class Solution {
public:
    string sortString(string s) {
        // 思路：对字符串 s 进行排序，然后按照要求分别从前往后和从后往前构造子字符串，且需要标注已使用过对字符下标
        int n = s.length();
        sort(s.begin(), s.end());
        string ans = "";
        vector<bool> book(n, false);

        int flag = 0;
        
        while (ans.length() != n) {
            char ch = 'a' - 1;
            if (flag % 2 == 0) {
                for (int i = 0; i < n; i++) {
                    if (book[i]) continue;
                    if (ch == 'a' - 1) {
                        book[i] = true;
                        ch = s[i];
                        ans += ch;
                        continue;
                    }
                    if (ch < s[i]) {
                        book[i] = true;
                        ch = s[i];
                        ans += ch;
                    }
                }
            } else {
                for (int i = n - 1; i >= 0; i--) {
                    if (book[i]) continue;
                    if (ch == 'a' - 1) {
                        book[i] = true;
                        ch = s[i];
                        ans += ch;
                        continue;
                    }
                    if (ch > s[i]) {
                        book[i] = true;
                        ch = s[i];
                        ans += ch;
                    }
                }
            }

            flag++;
        }
        
        return ans;
    }
};