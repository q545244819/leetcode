class Solution {
public:
    string reverseWords(string s) {
        vector<string> S;
        int n = s.length(), i = 0, j = 0;
        // 处理边界情况
        if (n == 1 && s == " ") return "";
        // 思路：双指针
        // 1. 若指针 1 的位置在空格且前一个字符不是空格，则表示指针 1 到指针 2 范围内是一个单词
        // 2. 每一次指针 1 走到空格位置，指针 2 需要移动到当前指针 1 的后一位
        // 3. 使用 substr 从 i 的位置开始截取长度位 i - j 的子字符串放入栈中
        // 4. 拼接字符串，最后一单词后不需要家空格，每一个单词之间添加空格
        for (; i < n; i++) {
            if (s[i] == ' ') { // 1
                if (i - 1 >= 0 && s[i - 1] != ' ')
                    S.push_back(s.substr(j, i - j)); // 3
                j = i + 1; // 2
            }
        }
        if (i > j)
            S.push_back(s.substr(j, i - j + 1)); // 3
        
        string ans = "";
        for (int i = S.size() - 1; i >= 0; i--) { // 4
            ans += S[i];
            if (i > 0)
                ans += " ";
        }

        return ans;
    }
};