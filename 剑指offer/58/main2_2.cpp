class Solution {
public:
    string reverseLeftWords(string s, int n) {
        // 思路：反转
        // 1.首先反转需要左旋转的字符串
        // 2.反转剩余的字符串
        // 3.整个字符串反转，输出正确答案
        reverseStr(s, 0, n - 1); // 1
        reverseStr(s, n, s.length() - 1); // 2
        reverseStr(s, 0, s.length() - 1); // 3
        return s;
    }
    void reverseStr (string& s, int l, int r) {
        while (l < r)
            swap(s[l++], s[r--]);
    }
};