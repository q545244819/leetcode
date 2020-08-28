class Solution {
public:
    string reverseLeftWords(string s, int n) {
        // 思路：直接使用字符串内置 substr 方法
        // 1.截取需要添加到后面的子字符串
        // 2.将截取到的子字符串追加到原字符串后面
        // 3.处理原字符串，返回正确答案
        string t = s.substr(0, n); // 1
        int len = s.length();
        s += t; // 2
        return s.substr(n, len); // 3
    }
};