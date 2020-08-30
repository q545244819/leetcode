class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0, n = s.length();
        while (j < n) {
            if (s[j] == ' ') {
                reverseStr(s, i, j - 1);
                i = j + 1;
            }
            j++;
        }
        if (i < j)
            reverseStr(s, i, j - 1);
        return s;
    }

    void reverseStr (string& s, int l, int r) {
        while (l < r)
            swap(s[l++], s[r--]);
    }
};
